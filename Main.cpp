#include<iostream>
#include<vector>
#include<map>
#include<string>

bool running = true;

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
        for ( auto &i : borrowedBooks ) {
            std::cout << i.title;
        }
    }

    void set_book(book &Book) {
        borrowedBooks.push_back(Book);
    }

    void set_name(std::string name) {
        this->name = name;
    }

    std::string get_name() {
        return this->name;
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
        newBook.available = true;

        books.push_back(newBook);
    }

    void display_books() {
        for (auto &i : books ) {
            if ( i.available == true ) {
                std::cout << i.title << " || "; std::cout << i.author << " || " << " Available ";
            }

            else if (i.available == false) {
                std::cout << "Not Available" << std::endl;
            }


        }
    }

    void search_book(std::string &title) {
        for (auto &i : books ) {
            if( i.title == title ) {
                std::cout << i.title << std::endl;
                std::cout << i.author << std::endl;
                std::cout << i.available << std::endl;

            }

        }
    }

    void borrow_book(std::string &title, user &user) {
        for (auto &i : books) {
            if(i.available == true) {
                if (i.title == title) {
                    user.set_book(i);
                    i.available = false;
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

        switch (input) {
            case 1: {
                std::string title, author;
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                std::cout << "Enter author: ";
                std::getline(std::cin, author);
                Library.add_book(title, author);
                break;
            }
            case 2:
                Library.display_books();
            break;
            case 3: {
                std::string title, username;
                std::cout << "Enter your username: ";
                std::getline(std::cin, username);
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                user usr;
                usr.set_name(username);
                Library.borrow_book(title, usr);
                break;
            }
            case 4: {
                std::string title, username;
                std::cout << "Enter your username: ";
                std::getline(std::cin, username);
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                user usr;
                usr.set_name(username);
                Library.return_book(title, usr);
                break;
            }
            case 5: {
                std::string title;
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                Library.search_book(title);
                break;
            }
            case 6:
            std::cout << "Exiting program..." << std::endl;
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

    }while(running == true);




    return 0;
}