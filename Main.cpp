#include<iostream>
#include<vector>
#include<map>
#include<string>

bool running = false;

struct book {
    std::string title;
    std::string author;
    bool available;
};

class user {

private:
    std::string name;
    std::vector<book> borrowedBooks;

public:

    void view_borrowed() {
        for ( auto i : borrowedBooks ) {
            std::cout << i.title;
        }
    }

    void set_book(book &Book) {
        borrowedBooks.push_back(Book);
    }



};

class library {
private:
    std::vector<book> books;
    std::map<user, book> borrowedBooks;

public:
    void add_book(std::string &title, std::string &author ) {
        book newBook;
        newBook.title = title;
        newBook.author = author;
        newBook.available = false;

        books.push_back(newBook);
    }

    void display_books() {
        for (auto i : books ) {
            std::cout << i.title << " || "; std::cout << i.author << " || ";
            if(i.available == false) {
                std::cout << "Not Available" << std::endl;
            }
            else if(i.available == true) {
                std::cout << "Available" << std::endl;
            }

        }
    }

    void search_book(std::string &title) {
        for (auto i : books ) {
            if( title == title ) {
                std::cout << i.title << "Found" << std::endl;
            }

        }
    }

    void borrow_book(std::string &title, user &user) {
        for (auto i : books) {
            if(i.available == true) {
                if (i.title == title) {
                    user.set_book(i);
                }
            }
            else{
            std::cout << "Not Available" << std::endl;};
        }

    }

    void return_book(std::string &title, user &user) {
        book newBook;
        newBook.title = title;

        books.push_back(newBook);

        borrowedBooks.insert(std::pair<std::string,book>(newBook.title,newBook));
    }


};

class userInterface {
    library Library;


public:

    void displayInterface() {
        std::cout << "1. Add a book \n";
        std::cout << "2. Display all available books\n";
        std::cout << "3. Borrow a book\n";
        std::cout << "4. Return a book\n";
        std::cout << "5. Search for a book\n";
        std::cout << "6. Exit the system\n";

    }

    void handleInput() {
        int input;
        std::cin >> input;
        std::cin.ignore();


        switch(input) {
            case 1:
                std::string title;
            std::cin >> title;
            std::string author;
            std::cin >> author;

                Library.add_book(title,author);
                break;

            case 2:
                Library.display_books();
                break;

            case 3:
                std::string btitle;
            std::cin >> btitle;
            user user;
                Library.borrow_book(btitle, user);

                break;

            case 4:


                break;

            case 5:

                break;

            case 6:
                std::cout << "exiting program..." << std::endl;
                running = false;

                break;


        }





    }
};


int main() {
    userInterface Program;
    do {
    Program.displayInterface();
    Program.handleInput();
    running = true;
    }while(running == true);




    return 0;
}