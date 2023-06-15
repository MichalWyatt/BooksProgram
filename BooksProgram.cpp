// BooksProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include <fstream>
//#include "bookType.h"

using namespace std;

class bookType    //class definition
{

private:
    double price = 0;
    int yearPublished = 0;
    int numAuthors = 0;
    int bookCopies;
    static int bookInventory;
   
    string ISBN = "";
    string publisher = "";
    string title = "";
    string authors[4];
       

public:
    
    bookType();
    static int numOfBooksInventory()
    {
        return bookInventory;
    }

    string getTitle();
    bool compareTitle(string);
    void setTitle(string);

    double getPrice();
    void setPrice(double pr);
    void updatePrice(double pric);

    int getYearPublished();
    void setYearPublished(int publish);

    int getBookCopies();
    void setbookCopies(int copies);
    void updateCopies(int);

    string getISBN();
    void setISBN(string is);
    bool compareISBN(string);

    string getPublisher(string publisher);
    void setPublisher(string pub);


    string* getAuthors();
    void setAuthors(string authors[], int count);
    void setNumAuthors(int na);
    string getNumAuthors();

    bookType(string a, string b[], string c, int d, string e, double f, int g, int h);
};

int bookType::bookInventory = 0;  

//setter and getter methods
void bookType::setPrice(double pr)  //Method definition of setPrice
{
    price = pr;
}
void bookType::updatePrice(double pric)
{
    this->price = pric;
}
double bookType::getPrice()
{
    return price;
}


void bookType::setYearPublished(int publish)
{
    yearPublished = publish;
}
int bookType::getYearPublished()
{
    return yearPublished;
}


void bookType::setbookCopies(int copies)
{
    bookCopies = copies;
}
int bookType::getBookCopies()
{
    return bookCopies;
}
void bookType::updateCopies(int myCopies) 
{
    bookCopies = myCopies;
}


void bookType::setNumAuthors(int numberAuthor)
{
    numAuthors = numberAuthor;
}
string* bookType::getAuthors() //Method definition of getAuthors
{
    return authors;
}


void bookType::setISBN(string is)
{
    ISBN = is;
}
string bookType::getISBN()
{
    return ISBN;
}
bool bookType::compareISBN(string otherISBN) // Method definition of compareTitle 
{
    if (ISBN.compare(otherISBN) == 0)
        return true;
    else
        return false;
}


void bookType::setPublisher(string pub)
{

}
string bookType::getPublisher(string publisher)  //Method definition of getPublisher
{
    return publisher;
}


void bookType::setTitle(string t)  //Method definition of setTitle
{
    title = t;
    
}
string bookType::getTitle()
{
    return title;
}
bool bookType::compareTitle(string otherTitle) // Method definition of compareTitle 
{
    if (title.compare(otherTitle) == 0)
        return true;
    else
        return false;
}


void bookType::setAuthors(string authors[], int count)  //Method definition of setAuthor
{
    for (int i = 0; i < count; ++i)
    {
        authors[i] = authors[i];
    }
}


bookType::bookType()
{
    title = "";
    for (int i = 0; i < 4; i++)
        authors[i] = "";
    publisher = "";
    yearPublished = 0;
    ISBN = "";
    price = 0;
    bookCopies = 0;
    numAuthors = 0;
    bookInventory = 0;
}

bookType::bookType(string a, string b[], string c,int d, string e, double f, int g, int h)
{
    title = a;
    for (int i = 0; i < h; i++)
        authors[i] = b[i];
    publisher = c;
    yearPublished = d;
    ISBN = e;
    price = f;
    bookCopies = g;
    numAuthors = h;
    bookInventory++;
}


int main()
{
    
    {
        bookType books[100]; //declares array of 100

        int selection;  //declare variables
        string str;
        int userInput;
        int i;
        //int count = bookType::numOfBooksInventory();
        double price;
        int copies;

        bookType book1; 
        book1.setTitle("ABC");      
        book1.setISBN("555666");
        book1.setPublisher("Cleveland Brown");
        book1.setYearPublished(1995);
        book1.setPrice(10.00);
        book1.setbookCopies(2);
        book1.setNumAuthors(2);

        bookType book2;
        book2.setTitle("123");
        book2.setISBN("444555");
        book2.setPublisher("Bob Doyle");
        book2.setYearPublished(2001);
        book2.setPrice(11.00);
        book2.setbookCopies(2);
        book2.setNumAuthors(1);

        bookType book3;
        book3.setTitle("The Persecuted Church");
        book3.setISBN("777777");
        book3.setPublisher("Cory Boon");
        book3.setYearPublished(2021);
        book3.setPrice(30.00);
        book3.setbookCopies(100);
        book3.setNumAuthors(1);

        bookType book4;
        book4.setTitle("Horizon");
        book4.setISBN("212121");
        book4.setPublisher("Lucas Smith");
        book4.setYearPublished(1922);
        book4.setPrice(29.99);
        book4.setbookCopies(12);
        book4.setNumAuthors(1);

        bookType book5;
        book5.setTitle("C++ For Dummies");
        book5.setISBN("001001");
        book5.setPublisher("C++ Master");
        book5.setYearPublished(1995);
        book5.setPrice(15.00);
        book5.setbookCopies(22);
        book5.setNumAuthors(1);

        books[0] = book1;
        books[1] = book2;
        books[2] = book3;
        books[3] = book4;
        books[4] = book5; 

     

        do
        { 
            int count = bookType::numOfBooksInventory();
            cout << "\nPlease make a selection\n";
            cout << "1. Search for book by title or ISBN.\n";
            cout << "2. Add a new book to inventory.\n";
            cout << "3. Update the number of copies on hand\n";
            cout << "4. Update the price of a book\n";
            cout << "5. Exit Program\n";
            cin >> selection;
            cin.ignore();
            switch (selection)
            {
                //Search for a book by its title or ISBN
            case 1:
            {
                bool found = false;
                
                cout << "\n\tSearch by title or ISBN: ";

                getline(cin, str);

                for (i = 0; i <= count; i++)
                    if (books[i].compareTitle(str) || books[i].compareISBN(str)) {
                        found = true;
                        break;
                    }


                if (!found)
                    cout << "\tBook not found.\n\n";
                else
                    cout << "\tBook found.\n\n ";

                break;
            }
            case 2:
            {   //Add a new book to inventory
                string authors[4];
                cout << "\n\tAdd a new book to inventory. ";
                cout << "\n\tEnter the Book title: ";  //Input for title of book
                getline(cin, str);
                books[count].setTitle(str);
                cout << "\n\tEnter the ISBN: ";  //Input for ISBN
                getline(cin, str);
                books[count].setISBN(str);
                cout << "\n\tEnter the Publisher Name: "; //Input for name of publisher
                getline(cin, str);
                books[count].setPublisher(str);
                cout << "\n\tEnter the Number of Authors: "; //Input for number of authors
                cin >> userInput;
                cin.ignore();
                books[count].setNumAuthors(userInput);
                for (int j = 0; j < userInput; ++j)
                {
                    cout << "\n\tEnter name of Author: ";
                    getline(cin, str);
                    
                    authors[j] = str;
                }
                books[count].setAuthors(authors, userInput);

                cout << "\n\tEnter year book was pulished: ";  //Input of year book was published
                cin >> userInput;
                books[count].setYearPublished(userInput);
                cout << "\n\tEnter price per copy: "; //Input of price per copy
                cin >> userInput;
                books[count].setPrice(userInput);
                cout << "\n\tThe new book in database is " << books[count].getTitle() << "." << endl;
                cin.ignore();
                break;
            }
            case 3:
            { 
                bool found = false;
                int index;
                //Update the number of copies on hand
                cout << "\n\tEnter book title to search:\n ";
                cin >> str;

                for (i = 0; i <= count; i++)
                    if (books[i].compareTitle(str))
                    {
                        found = true;
                        index = i;
                        break;
                    }
                     

                if (!found)
                    cout << "\n\tBook not found.";
                else
                {
                    cout << "\n\tEnter the number of copies ";
                    cin >> copies;
                    books[index].updateCopies(copies);
                    cout << books[index].getTitle() << " now has " << books[index].getBookCopies() << " copies " << endl;
                } break;
            }
            case 4:
            {
                bool found = false;
                int index;
                //Update the price of a book
                cout << "Enter book title to update it's price: \n";
                cin >> str;
                for (i = 0; i <= count; i++)
                    if (books[i].compareTitle(str))
                    {
                        found = true;
                        index = i;
                        break;
                    }


                if (!found)
                    cout << "\n\tBook not found.";
                else
                {
                    cout << "\n\tEnter new price: ";
                    cin >> price;
                    books[index].updatePrice(price);
                    cout << books[index].getTitle() << " now costs " << books[index].getPrice() << endl;
                } break;
            }
            default:
                break;
            
            }
                
        }while (selection != 5);
    }
}
