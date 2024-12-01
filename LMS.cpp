#include <iostream>
#include <string>
#include <fstream>
using namespace std;

			//			Menu Functions

void header();
void option();
		
			// 			Admin Functions

void addBook(string title[], string author[], int year[], bool isBorrow[], int& bookCount, int maxBook);
void listBooks  (string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount);
void updateBooks(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount);
void deleteBooks(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount);

			//			User Functions

void searchBook(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount);
void borrowBook(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount);
void returnBook(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount);

			// 			File Handling Functions

void saveBooksToFile  (string titles[], string authors[], int years[], bool isBorrowed[], int bookCount);
void loadBooksFromFile(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount);

int main()
{
	int maxBooks = 100;
    string titles[maxBooks];
    string authors[maxBooks];
    int years[maxBooks];
    bool isBorrowed[maxBooks] = {false};
    int bookCount = 0;
	string user, pwd;
    bool userSearchFlag = false;
	char input = '0', loggedIn = '0';
	
	loadBooksFromFile(titles, authors, years, isBorrowed, bookCount);
	
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
				saveBooksToFile(titles, authors, years, isBorrowed, bookCount);
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
						addBook(titles, authors, years, isBorrowed, bookCount, maxBooks);
						break;
					}
					
					case '2':
					{
						deleteBooks(titles, authors, years, isBorrowed, bookCount);
						break;
					}
					
					case '3':
					{
						listBooks(titles, authors, years, isBorrowed, bookCount);
						break;
					}
					
					case '4':
					{
						updateBooks(titles, authors, years, isBorrowed, bookCount);
						break;
					}
					
					case '0':
					{
						cout <<endl 
							 << "Logged out Successfully. " 
							 << endl;
						saveBooksToFile(titles, authors, years, isBorrowed, bookCount);
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
						listBooks(titles, authors, years, isBorrowed, bookCount);
						break;
					}
					
					case '2':
					{
						searchBook(titles, authors, years, isBorrowed, bookCount);
						break;
					}
					
					case '3':
					{
						borrowBook(titles, authors, years, isBorrowed, bookCount);
						saveBooksToFile(titles, authors, years, isBorrowed, bookCount);
						break;
					}
					
					case '4':
					{
						returnBook(titles, authors, years, isBorrowed, bookCount);
						saveBooksToFile(titles, authors, years, isBorrowed, bookCount);
						break;
					}
					
					case '0':
					{
						cout <<endl 
							 << "Thank you for using the system. " 
							 << endl;
						saveBooksToFile(titles, authors, years, isBorrowed, bookCount);
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


void addBook(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount, int maxBooks)
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
	getline(cin,titles[bookCount]);
	cout << endl
		 << " Enter the name of the author: ";
	getline(cin,authors[bookCount]);
	cout << endl
		 << " Enter the year of publication: ";
	cin  >> years[bookCount];
	
	isBorrowed[bookCount] = {false};
	
	bookCount++;
	
	cout << endl 
		 << " Book added successfully. "
		 << endl;
}


void listBooks(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount)
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
				    << titles[i] 
					<<"\t\t\t" 
					<< authors[i] 
					<<"\t\t\t"
					<< years[i] 
					<< (isBorrowed[i]? "\t\t [Borrowed]":"\t\t [Available]")
			 << endl;
	}
		 
	return;
}


void updateBooks(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount)
{
	if(bookCount == 0)
	{
		cout << endl	
			 << " There is no book to update."
			 << endl;
		
		return;
	}
	
	listBooks(titles, authors, years, isBorrowed, bookCount);
	
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
			titles[index] = newTitle;
		}
		
		cout << endl 
			 << "Enter name of the author (or press 0 to remain unchanged): ";
		getline(cin,newAuthor);
		
		if(newAuthor != "0")
		{
			authors[index] = newAuthor;
		}
		
		cout << endl 
			 << "Enter the year of publication (or press 0 to remain unchanged): ";
		cin  >> newYear;
		
		if(newYear > 0)
		{
			years[index] = newYear;
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

void deleteBooks(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount)
{
	if(bookCount == 0)
	{
		cout <<endl
			 << " There is no book available to delete."
			 <<endl;
		return;
	}
	
	listBooks(titles, authors, years, isBorrowed, bookCount);
	
	int index;
	
	cout <<endl
		 << "Enter the number of the book which you want to delete: ";
	cin  >> index;
	index --;
	
	if(index >= 0 && index < bookCount)
	{
		for(int i = index; i < bookCount-1; i++)
		{
			titles[i]     = titles[i+1];
			authors[i]    = authors[i+1];
			years[i]      = years[i+1];
			isBorrowed[i] = isBorrowed[i+1];
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

void searchBook(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount)
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
		if(titles[i].find(search) != string::npos)
		{
			cout <<endl << "*******************************************************************************************"
				 <<endl << "   Book Title                Author Name           Year of Publish         Status          "
				 <<endl << "*******************************************************************************************"
				 <<endl;
				 
			cout << i+1 << ".  "
						<< titles[i] 
						<<"\t\t\t" 
						<< authors[i] 
						<<"\t\t\t"
						<< years[i] 
						<< (isBorrowed[i]? "\t\t [Borrowed]":"\t\t [Available]")
				 << endl;
				 
			return;
		}
	}
	
	cout << endl
		 << " Book not found."
		 << endl;
}
	
void borrowBook(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount)
{
	if(bookCount == 0)
	{
		cout << endl
			 << " No Book Available to Borrow."
			 << endl;
		
		return;
	}
	
	listBooks(titles, authors, years, isBorrowed, bookCount);
	
	int index;
	
	cout <<endl
		 << "Enter the number of the book which you want to Borrow: ";
	cin  >> index;
	index --;
	
	if(index >= 0 && index < bookCount)
	{
		if(!isBorrowed[index])
		{
			isBorrowed[index] = true;
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

void returnBook(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount)
{
	if(bookCount == 0)
	{
		cout << endl
			 << " No Book Available to Borrow."
			 << endl;
		
		return;
	}
	
	listBooks(titles, authors, years, isBorrowed, bookCount);
	
	int index;
	
	cout <<endl
		 << "Enter the number of the book which you want to Return: ";
	cin  >> index;
	index --;
	
	if(index >= 0 && index < bookCount)
	{
		if(isBorrowed[index])
		{
			isBorrowed[index] = false;
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

void saveBooksToFile(string titles[], string authors[], int years[], bool isBorrowed[], int bookCount)
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
		fout << titles[i]
			 << endl
			 << authors[i]
			 << endl
			 << years[i]
			 << endl
			 << isBorrowed[i]
			 << endl;
	}
	
	fout.close();
}

void loadBooksFromFile(string titles[], string authors[], int years[], bool isBorrowed[], int& bookCount)
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
		getline(fin,titles[i]);
		getline(fin,authors[i]);
		fin >> years[i];
		fin >> isBorrowed[i];
		fin.ignore();
	}
	
	fin.close();
}