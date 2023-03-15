#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

//structure definition
struct Book
{
    char title[50];
    char a_name[50];
    long long isbn;

    void addBook()			// function to add books in the library
    {
        static int j = 0;
        j++;
        cout<<"Enter book title "<<j<<": ";
        cin.getline(title,50);
        cout<<"Enter author name: ";
        cin.getline(a_name,50);
        cout<<"Enter ISBN: ";
        cin>>isbn;
        cin.ignore();		// used to empty the buffer
        cout<<endl;
    }

    void display()			// function to display the books in the library
    {
    	static int i = 0;

    	if(i==0)			// condition to print the menu bar only once, not on every call
		{
    		cout<<"**************************************************************************"<<endl;
    		cout<<setw(30)<<left<<"Book Title"<<setw(30)<<left<<"Author Name"<<setw(30)<<left<<"ISBN"<<endl;
    		cout<<"**************************************************************************"<<endl;
    	}
    	i++;
        cout<<setw(30)<<left<<title<<setw(30)<<left<<a_name<<setw(30)<<left<<isbn<<endl;
    }
};
//functions declaration
void searchBook(Book b[]);
void deleteBook(Book b[]);

// main function
int main()
{
    Book b[10];
    for(int i=0; i<10; i++)		
        b[i].addBook();    

    
    //asking the user what to do
    cout<<"Enter 1 to see the library."<<endl
    <<"Enter 2 to search the book in the library."<<endl
    <<"Enter 3 to delete a book's information from the library."<<endl;
    int choice;
    cout<<endl<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            for(int j=0; j<10; j++)
                b[j].display();
                break;
        case 2:
            searchBook(b);
            break;
        case 3:
            deleteBook(b);
            break;
        default:
            cout<<"You entered the wrong choice. Please try again.";
    }
return 0;
}


void searchBook(Book b[]) 		// function to search a book in the library
{
	char s_name[50];
    cin.ignore();
    cout<<endl<<"Enter book title to search the book in library: ";
    cin.getline(s_name,50);

    for(int i=0; i<10; i++)
    {
        if (strcmp(s_name, b[i].title) == 0)
        {
            cout<<"Book title: "<<b[i].title<<endl
            <<"Author name: "<<b[i].a_name<<endl<<
            "ISBN: "<<b[i].isbn;
            break;
        }
        else 
        {
            if(i==9)
                cout<<"This book is not found in the library.";
        }
    }
}


void deleteBook(Book b[])			// function to delete a book's information from the library
{
	char d_name[50];
    long long d_isbn;
    int choice;
    cout<<endl<<endl<<"Enter 1 to delete the book's information with title."<<endl<<
	"Enter 2 to delete the book's information with ISBN."<<endl<<endl;
    cout<<"Enter choice: "; 
    cin>>choice;
    switch(choice)
    {
        case 1:
           	cin.ignore();
            cout<<"Enter book title to delete the book info: ";
            cin.getline(d_name, 50);
            break;
        case 2:
            cout<<"Enter ISBN to delete the book info: ";
            cin>>d_isbn;
    }
    if(choice == 1)		// delete the book's information from the library with book title
    {
        for(int m=0; m<10; m++)
        {
            if(strcmp(d_name, b[m].title)==0)
            {
                for(int n=m; n<9; n++)
                {
                    b[m] = b[m+1];
                    m++;
                }
                break;
            }
            else
            {
                if(m==9)
                {
                    cout<<"This book is not found in the library.";
                    return;
                }
            }
        }
    }

    if(choice == 2)         // delete the book's information from the library with isbn
	{
    	for(int j=0; j<10; j++)
        {
        	if (d_isbn == b[j].isbn)
        	{
        		for(int k = j; k<9; k++)
        			b[k] = b[k+1];
        		break;
			}
			else
        	{
            	if(j==9)
				{
			    	cout<<"This book is not found in the library.";
			    	return;
			    }
        	}
		}
	}
	cout<<endl<<"Updated list:"<<endl<<endl;
	cout<<"****************************************************************************"<<endl;
	cout<<setw(30)<<left<<"Book title"<<setw(30)<<left<<"Author name"<<setw(30)<<left<<"ISBN"<<endl;
	cout<<"****************************************************************************"<<endl;
	for(int j = 0; j<9; j++)
    	cout<<setw(30)<<left<<b[j].title<<setw(30)<<left<<b[j].a_name<<setw(30)<<left<<b[j].isbn<<endl;
}
