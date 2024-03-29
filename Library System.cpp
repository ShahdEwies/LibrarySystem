// Library System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

const int librarySize = 1000;
int booksId[librarySize] = {};
string booksTitle[librarySize] = {};
string booksAuthor[librarySize] = {};
bool booksStatus[librarySize] = {};
int currentBookCount = 0;


// menus
// main menu
void mainMenu() {
	cout << "==========================\n";
	cout << "Welcome To Alex Library\n";
	cout << "==========================\n\n";
	cout << "choose an option below\n";
	cout << "1. Add a book\n";
	cout << "2. Borrow a book\n";
	cout << "3. Return a book\n";
	cout << "4. Delete a book\n";
	cout << "5. Update a book\n";
	cout << "6. List all books\n";
	cout << "7. Exit\n";
	cout << "Your choice: ";

}

// update menu
void updateMenu() {
	cout << "What do you want to update? \n";
	cout << "1. Book title " << endl;
	cout << "2. Book Author " << endl;
	cout << "3. Is available or not " << endl;
	cout << "4. Exit" << endl;
	cout << "Your Choice : ";
}

// search for book by id
int searchBookById(int id) {
	for (int i = 0; i < currentBookCount; i++) {
		if (id == booksId[i])
			return i; // 0 -> 999
	}
	return -1;
}


// adding book
void addBook(string title, string author) {
	booksId[currentBookCount] = currentBookCount + 1;
	booksTitle[currentBookCount] = title;
	booksAuthor[currentBookCount] = author;
	booksStatus[currentBookCount] = true;
	currentBookCount++;
	cout << "BOOK ADDED SUCCESSFULLY\n";
}


// diplay book info
void displayBookInfo(int id) {
	if (searchBookById(id) == -1) {
		cout << "Book with id " << id << " is not Exist\n";
		return;
	}
	cout << "Book Id: " << booksId[id - 1] << endl;
	cout << "Book Title: " << booksTitle[id - 1] << endl;
	cout << "Book Author: " << booksAuthor[id - 1] << endl;
	cout << "Book Status: " << (booksStatus[id - 1] ? "Availabe" : "NOT Availabe") << endl;
	cout << "=================================\n";

}

// listing books

void displayAllBooksInfo() {
	for (int i = 0; i < currentBookCount; i++) {
		displayBookInfo(booksId[i]);
	}
	cout << "\n\n\n";
}


// borrow book
void borrowBookById(int id) {
	if (searchBookById(id) == -1) {
		cout << "Book with id " << id << " is not Exist\n";
		return;
	}
	if (booksStatus[id - 1]) {
		booksStatus[id - 1] = false;
		cout << "BOOK BORROWED SUCCESSFULLY\n\n";
		return;
	}
	cout << "BOOK IS ALREADY BORROWED\n\n";
}

// return book
void returnBookById(int id) {
	if (searchBookById(id) == -1) {
		cout << "Book with id " << id << " is not Exist\n";
		return;
	}
	if (booksStatus[id - 1] == true) {
		cout << "BOOK IS ALEADY AVAIABLE\n";
		return;
	}
	booksStatus[id - 1] = true;
	cout << "BOOK IS RETURNED SUCCESSFULLY\n\n";
}


// delete a book
void deleteBookById(int id) {
	if (searchBookById(id) == -1) {
		cout << "Book with id " << id << " is not Exist\n";
		return;
	}
	int position = searchBookById(id); // index of the book i want to delete
	for (int i = position; i < currentBookCount; i++) {
		booksTitle[i] = booksTitle[i + 1];
		booksAuthor[i] = booksAuthor[i + 1];
		booksStatus[i] = booksStatus[i + 1];
		//booksId[i] = booksId[i + 1] - 1;
	}
	currentBookCount--;
	cout << "BOOK IS DELETED SUCCESSFULLY\n\n";

}

// update a book

void updateBookById(int id) {
	if (searchBookById(id) == -1) {
		cout << "Book with id " << id << " is not Exist\n";
		return;
	}
	int choice, position = searchBookById(id);
	string input;

	bool flag = true;

	while (flag) {
		updateMenu();
		cin >> choice;
		switch (choice) {
		case 1:
			// Title
			cout << "Enter new title: ";
			cin.ignore();
			getline(cin, input);
			//cin >> input;
			booksTitle[position] = input;
			break;
		case 2:
			// Author
			cout << "Enter new author name: ";
			cin.ignore();
			getline(cin, input);
			booksAuthor[position] = input;
			break;
		case 3:
			// Status
			cout << "Is a book availabe or not [Enter y or n]: ";
			cin.ignore();
			getline(cin, input);
			booksStatus[position] = (input == "y") ? true : false;
			break;
		case 4:
			// Exit
			flag = false;
			break;
		default:
			break;
		}
	}

	cout << "BOOK UPDATED SUCCESSFULLY\n\n";

}

void init() {

	addBook("How To Program with C++", "Harvey Deitel");
	addBook("Introduction to Algorithms", "Thomas H. Cormen");
	addBook("Clean Code", "Robert Cecil Martin");
	system("cls");

}

int main() {
	init();
	int id;
	string title, author;
	int choice;
	bool flag = true;
	while (flag)
	{
		mainMenu();
		cin >> choice;
		switch (choice) {
		case 1:
			// add a book
			cout << "Enter Book Title:";
			cin.ignore();
			getline(cin, title);
			cout << "Enter Book Author:";
			getline(cin, author);
			addBook(title, author);
			break;
		case 2:
			// borrow a book
			cout << "Enter book id that you want to borrow:";
			cin >> id;
			borrowBookById(id);
			break;
		case 3:
			// return a book
			cout << "Enter book id that you want to return:";
			cin >> id;
			returnBookById(id);
			break;
		case 4:
			// delete
			cout << "Enter book id that you want to delete:";
			cin >> id;
			deleteBookById(id);
			break;
		case 5:
			// update
			cout << "Enter book id that you want to update:";
			cin >> id;
			updateBookById(id);
			break;
		case 6:
			// Listing
			displayAllBooksInfo();
			break;
		case 7:
			flag = false;
			cout << "BYE BYE\n";
			Sleep(5000);
			// Exit
			break;
		default:
			break;

		}
		//getchar();
		system("pause");
		system("cls");
	}
}
