#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Book
{
		string titles;
		string authors;
		int years;
		bool isBorrowed;
};

bool confirmChoice();

			//			Menu Functions

void header();
void option();
		
			// 			Admin Functions

void addBook(Book books[], int& bookCount, int maxBook);
void listBooks  (Book books[], int& bookCount);
void updateBooks(Book books[], int& bookCount);
void deleteBooks(Book books[], int& bookCount);

			//			User Functions

void searchBook(Book books[], int& bookCount);
void borrowBook(Book books[], int& bookCount);
void returnBook(Book books[], int& bookCount);

			// 			File Handling Functions

void saveBooksToFile  (Book books[], int bookCount);
void loadBooksFromFile(Book books[], int& bookCount);



int main()
{
	int maxBooks = 100;
	int bookCount = 0;
	Book books[maxBooks];
	string user, pwd;
    bool userSearchFlag = false;
	char input = '0', loggedIn = '0';
	
	loadBooksFromFile(books, bookCount);
	
	header();
	
	do
	{
		option();
	
		cout << endl
			 << "Choose an option: ";
		cin  >> input;
		cout << endl;
		
		if (cin.fail() || (input != '1' && input != '2' && input != '0')) 
		{
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout << endl
				 << "Invalid choice!" 
				 << endl;
            continue;
        }
		
		switch (input)
        {

			case '1':
			{
				cout << endl
					 <<"Enter the username: ";
				cin  >> user;

				cout << endl
					 <<"Enter Password: ";
				cin  >> pwd;

				if (user == "Admin" && pwd == "PF2024")
				{
					loggedIn = '1';
				}    
				else
				{
					loggedIn = '8';
				}   
				break;
			}
				
			case '2':
			{
				userSearchFlag = true;
				
				if (userSearchFlag == true)
				{
					loggedIn = '2';
				}
				else
				{
					loggedIn = '8';
				}
				break;
			}
				
			case '0':
			{
				loggedIn = '7';
				cout << "Thank you for using system" 
					 << endl;
				saveBooksToFile(books, bookCount);
				break;
			}
			
			default:
			{
				cout << "Invalid choice!";
				break;
			}
        }
		if(loggedIn == '1')
		{
			do
			{
				cout << endl
					 << "Choose the desired option"
					 << endl   << endl
					 << "\t"   << "1. Add"
                     << "\t\t" << "2. Delete"
                     << "\t"   << "3. List"
					 << "\t\t" << "4. Update"
					 << "\t"   << "0. Logout"
					 << endl
					 << endl;
				
				cout << "Choose an option: ";
                cin  >> input;
				
				if (cin.fail() || (input != '1' && input != '2' && input != '0' && input != '3' && input != '4')) 
				{
					cin.clear();
					cin.ignore(1000, '\n'); 
					cout << endl
						 << "Invalid choice!" 
						 << endl;
					continue;
				}
				
				switch(input)
				{
					case '1':
					{
						addBook(books, bookCount, maxBooks);
						break;
					}
					
					case '2':
					{
						deleteBooks(books, bookCount);
						break;
					}
					
					case '3':
					{
						listBooks(books, bookCount);
						break;
					}
					
					case '4':
					{
						updateBooks(books, bookCount);
						break;
					}
					
					case '0':
					{
						cout <<endl 
							 << "Logged out Successfully. " 
							 << endl;
						saveBooksToFile(books, bookCount);
						break;
					}
					
					default:
					{
						cout << "Invalid choice.";
						break;
					}
				}
				
				
			}while(input != '0');
			
			input = '9';
		}
		else if(loggedIn == '2')
		{
			do
			{
				cout << endl
					 << "Choose the desired option"
					 << endl   << endl
					 << "\t"   << "1. Available Books"
                     << "\t"   << "2. Search Book"
                     << "\t\t" << "3. Borrow Book"
					 << endl   << endl
					 << "\t"   << "4. Return Book"
					 << "\t\t" << "0. Logout"
					 << endl
					 << endl;
					 
				cout << "Choose an option: ";
                cin  >> input;
				
				if (cin.fail() || (input != '1' && input != '2' && input != '0' && input != '3' && input != '4')) 
				{
					cin.clear();
					cin.ignore(1000, '\n'); 
					cout << endl
						 << "Invalid choice!" 
						 << endl;
					continue;
				}
				
				switch(input)
				{
					case '1':
					{
						listBooks(books, bookCount);
						break;
					}
					
					case '2':
					{
						searchBook(books, bookCount);
						break;
					}
					
					case '3':
					{
						borrowBook(books, bookCount);
						saveBooksToFile(books, bookCount);
						break;
					}
					
					case '4':
					{
						returnBook(books, bookCount);
						saveBooksToFile(books, bookCount);
						break;
					}
					
					case '0':
					{
						cout <<endl 
							 << "Thank you for using the system. " 
							 << endl;
						saveBooksToFile(books, bookCount);
						break;
					}
					
					default:
					{
						cout << "Invalid choice.";
						break;
					}
				}
				
				
			}while(input != '0');
			
			input = '9';
		}
		else if(loggedIn == '8')
		{
			cout <<endl
				 << "Invalid Credentials"
				 <<endl;
		}
	}while(input != '0');
	
	return 0;
	
	
}

void header()
{
	cout <<endl << "********************************************************************************"
		 <<endl 
		 <<endl << "                        Library Management System                               "
		 <<endl 
		 <<endl << "********************************************************************************"
		 <<endl;
}

void option()
{
	cout << endl  << "Choose the desired option:" 
		 << endl  << endl
		 <<"\t"   << "1. Administration Login"
		 <<"\t\t" << "2. Continue as User"
		 <<"\t\t" << "0. Exit"
		 <<endl;
}


void addBook(Book books[], int& bookCount, int maxBooks)
{
	if(bookCount >= maxBooks)
	{
		cout << endl
			 << " Memory is full. No more books can be added."
			 << endl;
		return;
	}
	
	
    cin.ignore(1000, '\n');
	
	cout << endl
		 << " Enter the title of the book: ";
	getline(cin,books[bookCount].titles);
	cout << endl
		 << " Enter the name of the author: ";
	getline(cin,books[bookCount].authors);
	cout << endl
		 << " Enter the year of publication: ";
	cin  >> books[bookCount].years;
	
	books[bookCount].isBorrowed = {false};
	
	bookCount++;
	
	cout << endl 
		 << " Book added successfully. "
		 << endl;
}


void listBooks(Book books[], int& bookCount)
{
	
	if(bookCount == 0)
	{
		cout << endl	
			 << " There is no book in the library."
			 << endl;
		
		return;
	}
	
	cout <<endl << "*******************************************************************************************"
		 <<endl << "   Book Title                Author Name           Year of Publish         Status          "
		 <<endl << "*******************************************************************************************"
		 <<endl;
		 
	for(int i = 0; i < bookCount; i++)
	{
		cout << i+1 << ".  " 
				    << books[i].titles 
					<<"\t\t\t" 
					<< books[i].authors 
					<<"\t\t\t"
					<< books[i].years 
					<< (books[i].isBorrowed? "\t\t [Borrowed]":"\t\t [Available]")
			 << endl;
	}
		 
	return;
}


void updateBooks(Book books[], int& bookCount)
{
	if(bookCount == 0)
	{
		cout << endl	
			 << " There is no book to update."
			 << endl;
		
		return;
	}
	
	listBooks(books, bookCount);
	
	int index, newYear;
	string newTitle, newAuthor;
	
	cout << endl
		 << " Enter the number of the book to update: ";
	cin  >> index;
	index --;
	
	if(index >= 0 && index < bookCount)
	{
		cin.ignore();
		cout << endl 
			 << "Enter a new title (or press 0 to remain unchanged): ";
		getline(cin,newTitle);
		
		if(newTitle != "0")
		{
			books[index].titles = newTitle;
		}
		
		cout << endl 
			 << "Enter name of the author (or press 0 to remain unchanged): ";
		getline(cin,newAuthor);
		
		if(newAuthor != "0")
		{
			books[index].authors = newAuthor;
		}
		
		cout << endl 
			 << "Enter the year of publication (or press 0 to remain unchanged): ";
		cin  >> newYear;
		
		if(newYear > 0)
		{
			books[index].years = newYear;
		}
		
		cout << endl
			 << " Book updated successfully. "
			 << endl;
	}
	else
	{
		cout << endl
			 << " Invalid Input "
			 << endl;
	}
}

void deleteBooks(Book books[], int& bookCount)
{
	if(bookCount == 0)
	{
		cout <<endl
			 << " There is no book available to delete."
			 <<endl;
		return;
	}
	
	listBooks(books, bookCount);
	
	int index;
	
	cout <<endl
		 << "Enter the number of the book which you want to delete: ";
	cin  >> index;
	index --;
	
	bool choice = confirmChoice();
	
	if(choice)
	{
		if(index >= 0 && index < bookCount)
		{
			for(int i = index; i < bookCount-1; i++)
			{
				books[i].titles     = books[i+1].titles;
				books[i].authors    = books[i+1].authors;
				books[i].years      = books[i+1].years;
				books[i].isBorrowed = books[i+1].isBorrowed;
			}
			
			bookCount--;
			cout << endl
				 << " Book Deleted Successfully."
				 << endl;
		}
		else
		{
			cout <<endl
				 << " Invalid Input."
				 <<endl;
		}
	}
	else
	{
		cout << endl
			 << " The book is not deleted."
			 << endl;
	}
}

void searchBook(Book books[], int& bookCount)
{
	if(bookCount == 0)
	{
		cout << endl
			 << " No Book Available."
			 << endl;
		
		return;
	}
	
	string search;
	cin.ignore();
	
	cout << endl
		 << " Enter title of the book to search: ";
	getline(cin,search);
	
	for(int i = 0; i < bookCount; i++)
	{
		if(books[i].titles.find(search) != string::npos)
		{
			cout <<endl << "*******************************************************************************************"
				 <<endl << "   Book Title                Author Name           Year of Publish         Status          "
				 <<endl << "*******************************************************************************************"
				 <<endl;
				 
			cout << i+1 << ".  "
						<< books[i].titles 
						<<"\t\t\t" 
						<< books[i].authors 
						<<"\t\t\t"
						<< books[i].years
						<< (books[i].isBorrowed? "\t\t [Borrowed]":"\t\t [Available]")
				 << endl;
				 
			return;
		}
	}
	
	cout << endl
		 << " Book not found."
		 << endl;
}
	
void borrowBook(Book books[], int& bookCount)
{
	if(bookCount == 0)
	{
		cout << endl
			 << " No Book Available to Borrow."
			 << endl;
		
		return;
	}
	
	listBooks(books, bookCount);
	
	int index;
	
	cout <<endl
		 << "Enter the number of the book which you want to Borrow: ";
	cin  >> index;
	
	if (cin.fail()) 
	{
		cin.clear();
		cin.ignore(1000, '\n'); 
		cout << endl
			 << "Invalid choice!" 
			 << endl;
		return;
	}
	
	index --;
	bool choice = confirmChoice();
	
	if(choice)
	{
		if(index >= 0 && index < bookCount)
		{
			if(!books[index].isBorrowed)
			{
				books[index].isBorrowed = true;
				cout << endl
					 << " You have borrowed the book."
					 <<endl;
			}
			else
			{
				cout << endl
					 << " The book is already borrowed."
					 <<endl;
			}
		}
		else
		{
			cout << endl
				 << " Invalid Input"
				 <<endl;
		}
	}
	else
	{
		cout << endl
			 << " The book is not borrowed."
			 << endl;
	}
	
}

void returnBook(Book books[], int& bookCount)
{
	bool flag = false;
	
	if(bookCount == 0)
	{
		cout << endl
			 << " There is no Book that is Borrow."
			 << endl;
		
		return;
	}
	
	for(int i = 0; i < bookCount; i++)
	{
		if(books[i].isBorrowed)
		{
			flag = true;
			break;
		}
	}
	
	if(flag)
	{
		listBooks(books, bookCount);
		
		int index;
		
		cout <<endl
			 << "Enter the number of the book which you want to Return: ";
		cin  >> index;
		
		if (cin.fail()) 
		{
			cin.clear();
			cin.ignore(1000, '\n'); 
			cout << endl
				 << "Invalid choice!" 
				 << endl;
			return;
		}
		
		index --;
		
		if(index >= 0 && index < bookCount)
		{
			if(books[index].isBorrowed)
			{
				books[index].isBorrowed = false;
				cout << endl
					 << " You have returned the book."
					 <<endl;
			}
			else
			{
				cout << endl
					 << " The book is not borrowed."
					 <<endl;
			}
		}
		else
		{
			cout << endl
				 << " Invalid Input"
				 <<endl;
		}
	}
	else
	{
		cout << endl
			 << " No Borrow Book to Return."
			 << endl;
		
		return;
	}
}

void saveBooksToFile(Book books[], int bookCount)
{
	ofstream fout("Books.txt");
	
	if(!fout)
	{
		cout << endl
			 << " Enable to open file for saving."
			 << endl;
		return;
	}
	
	fout << bookCount << endl;
	
	for(int i = 0; i < bookCount; i++)
	{
		fout << books[i].titles
			 << endl
			 << books[i].authors
			 << endl
			 << books[i].years
			 << endl
			 << books[i].isBorrowed
			 << endl;
	}
	
	fout.close();
}

void loadBooksFromFile(Book books[], int& bookCount)
{
	ifstream fin("Books.txt");
	
	if(!fin)
	{
		cout << endl
			 << " No data fouond. "
			 << endl;
		return;
	}
	
	fin >> bookCount;
	fin.ignore();
	
	for(int i = 0; i < bookCount; i++)
	{
		getline(fin,books[i].titles);
		getline(fin,books[i].authors);
		fin >> books[i].years;
		fin >> books[i].isBorrowed;
		fin.ignore();
	}
	
	fin.close();
}

bool confirmChoice()
{
	char choice;
	cout << endl
		 << " Are you sure (y/n):";
	cin  >> choice;
	
	if(choice == 'y' || choice == 'Y')
	{
		return true;
	}
	else
	{
		return false;
	}
}