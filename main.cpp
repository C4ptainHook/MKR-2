/* Описати клас, що містить інформацію про книги бібліотеки і кількість їх екземплярів.
 * З використанням композиції  реалізувати поле «книга» таким чином, щоб можна було мати доступ до окремих складових інформації про книги (назва, автори, рік видання).

Для створення об’єктів даного класу передбачити конструктор, що ініціалізує константними значеннями.
 Передбачити можливість перегляду і зміни складових частин класу, а також можливість підрахунку загальної кількості об’єктів-книг, створених в процесі роботи програми.

Створити декілька (не менше шести) об'єктів даного класу, у тому числі і пустих.
 Ініціалізувати пусті об’єкти в процесі роботи програми. Підрахувати загальну кількість створених об'єктів і вивести їх вміст.*/

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Book{
    static int numb;
    string title;
    string author;
    int year;
public:
    Book(string _title="empty",string _author="empty", int _y=0){
        title=_title; author=_author; year=_y;
        numb++;
    }
    ~Book(){numb--;}
    void setT(string&_title) {
        title=_title;
    }
    void setA(string& _author) {
        author=_author;
    }
    void setY(int _year) {
        year=_year;
    }
    string getT()  {return title;}

    string getA() {return author;}

    int getY() {return year;}

    static int bookCounter(){
        return numb;
    }
};

int Book::numb = 0;

class Library{
    int size;
    Book* shelf;
public:
    Library(int _size=0) {
        size=_size;
        shelf = new Book[_size];
    }
    ~Library(){
        delete[] shelf;
    }
    void print();
    Book& operator[](int ind);
};
void Library::print() {
    for (int i = 0; i < size; ++i) {
        cout<<"Title: "<<shelf[i].getT()<<"; ";
        cout<<"Author: "<<shelf[i].getA()<<"; ";
        cout<<"Published in: "<<shelf[i].getY()<<"\n";
        cout<<"--------------------------------------"<<"\n";
    }
}
Book& Library::operator[](int ind) {
    if(ind>size-1) {throw invalid_argument("Fuck you dirty bastard");}
    else{return shelf[ind];}
}

int main() {
Library pack(2);
string a = "Fedir";
pack[0].setA(a);
a = "Notes";
pack[0].setT(a);
a = "2023";
pack[0].setY(stoi(a));
pack.print();
cout<<"Books in total: "<<Book::bookCounter();
}
