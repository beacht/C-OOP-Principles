#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <iomanip>

class Student {
private:
    int admno;
    char sname[21];
    float eng;
    float math;
    float science;
    float total;

public:
    Student(int admno, const char* sname, float eng, float math, float science)
        : admno(admno), eng(eng), math(math), science(science) {
        strncpy(this->sname, sname, 20);
        this->sname[20] = '\0';
        total = ctotal();
    }

    float ctotal() {
        return eng + math + science;
    }

    void Takedata(int new_admno, const char* new_sname, float new_eng, float new_math, float new_science) {
        admno = new_admno;
        strncpy(sname, new_sname, 20);
        sname[20] = '\0';
        eng = new_eng;
        math = new_math;
        science = new_science;
        total = ctotal();
    }

    void Showdata() {
        std::cout << "Admission Number: " << admno << std::endl;
        std::cout << "Student Name: " << sname << std::endl;
        std::cout << "English Score: " << eng << std::endl;
        std::cout << "Math Score: " << math << std::endl;
        std::cout << "Science Score: " << science << std::endl;
        std::cout << "Total Score: " << total << std::endl;
    }
};

class Batsman {
private:
    int bcode;
    std::string bname;
    int innings;
    int notout;
    int runs;
    double batavg;

public:
    void calcavg() {
        if (innings - notout > 0) {
            batavg = static_cast<double>(runs) / (innings - notout);
        } else {
            batavg = 0.0;
        }
    }

    void readdata(int new_bcode, const std::string& new_bname, int new_innings, int new_notout, int new_runs) {
        if (new_bcode >= 1000 && new_bcode <= 9999) {
            bcode = new_bcode;
        } else {
            std::cerr << "Invalid bcode. It should be a 4-digit number." << std::endl;
            return;
        }

        if (new_bname.length() <= 20) {
            bname = new_bname;
        } else {
            std::cerr << "Invalid bname. It should be up to 20 characters." << std::endl;
            return;
        }

        innings = new_innings;
        notout = new_notout;
        runs = new_runs;
        calcavg();
    }

    void displaydata() {
        std::cout << "Batsman Code: " << bcode << std::endl;
        std::cout << "Batsman Name: " << bname << std::endl;
        std::cout << "Innings: " << innings << std::endl;
        std::cout << "Not Out: " << notout << std::endl;
        std::cout << "Runs: " << runs << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Batting Average: " << batavg << std::endl;
    }
};

class TEST {
private:
    int TestCode;
    std::string Description;
    int NoCandidate;
    int CenterReqd;

public:
    int CALCNTR() {
        CenterReqd = (NoCandidate / 100) + 1;
        return CenterReqd;
    }

    void SCHEDULE() {
        std::cout << "Enter Test Code: ";
        std::cin >> TestCode;
        std::cin.ignore();
        std::cout << "Enter Description: ";
        std::getline(std::cin, Description);
        std::cout << "Enter Number of Candidates: ";
        std::cin >> NoCandidate;
        CALCNTR();
    }

    void DISPTEST() {
        std::cout << "Test Code: " << TestCode << std::endl;
        std::cout << "Description: " << Description << std::endl;
        std::cout << "Number of Candidates: " << NoCandidate << std::endl;
        std::cout << "Number of Centers Required: " << CenterReqd << std::endl;
    }
};

class Flight {
private:
    int flightNumber;
    std::string destination;
    float distance;
    float fuel;

public:
    void CALFUEL() {
        if (distance <= 1000)
            fuel = 500;
        else if (distance > 1000 && distance <= 2000)
            fuel = 1100;
        else
            fuel = 2200;
    }

    void FEEDINFO() {
        std::cout << "Enter Flight Number: ";
        std::cin >> flightNumber;
        std::cin.ignore();
        std::cout << "Enter Destination: ";
        std::getline(std::cin, destination);
        std::cout << "Enter Distance: ";
        std::cin >> distance;
        CALFUEL();
    }

    void SHOWINFO() {
        std::cout << "Flight Number: " << flightNumber << std::endl;
        std::cout << "Destination: " << destination << std::endl;
        std::cout << "Distance: " << distance << std::endl;
        std::cout << "Fuel: " << fuel << std::endl;
    }
};

class BOOK {
private:
    int BOOK_NO;
    char BOOKTITLE[20];
    float PRICE;

    //Calculates the total cost of buying N books where 1 book costs PRICE
    float TOTAL_COST(int N) {
        return N * PRICE;
    }

public:
    //Asks the user to input new book number, book title, and book price.
    void INPUT() {
        std::cout << "Enter BOOK Number: ";
        std::cin >> BOOK_NO;
        std::cin.ignore();
        std::cout << "Enter BOOK Title: ";
        std::cin.getline(BOOKTITLE, 20);
        std::cout << "Enter Price: ";
        std::cin >> PRICE;
    }

    //Asks the user how many copies will be purchased, and prints the cost for that many.
    void PURCHASE() {
        int N;
        std::cout << "Enter the number of copies to be purchased: ";
        std::cin >> N;
        float cost = TOTAL_COST(N);
        std::cout << "Total Cost: " << cost << std::endl;
    }
};

class REPORT {
private:
    int adno;
    char name[20];
    float marks[5];
    float average;

    //Gets the average score from the 5 marks
    void GETAVG() {
        float sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        average = sum / 5;
    }

public:
    //Sets the info for the report
    void READINFO() {
        do {
            std::cout << "Enter Admission Number (4 digits): ";
            std::cin >> adno;
        } while (adno < 1000 || adno > 9999);
        //Ensures adno is 4 digits

        std::cin.ignore();
        std::cout << "Enter Name: ";
        std::cin.getline(name, 20);
        std::cout << "Enter 5 Subject Marks: ";
        for (int i = 0; i < 5; i++) {
            std::cin >> marks[i];
        }
        GETAVG();
    }

    //Shows the info for the report
    void DISPLAYINFO() {
        std::cout << "Admission Number: " << adno << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            std::cout << marks[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Average: " << average << std::endl;
    }
};

class Rectangle {
private:
    float length;
    float width;

public:
    //Sets the length
    void setlength(float len) {
        length = len;
    }

    //Sets the width
    void setwidth(float wid) {
        width = wid;
    }

    //Gets the perimeter
    float perimeter() {
        return 2 * (length + width);
    }

    //Gets the area
    float area() {
        return length * width;
    }

    //Shows the length and width
    void show() {
        std::cout << "Length: " << length << std::endl;
        std::cout << "Width: " << width << std::endl;
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Perimeter: " << perimeter() << std::endl;
    }

    //Checks if 2 rectangles have equal areas
    bool sameArea(Rectangle other) {
        return area() == other.area();
    }
};

class Complex {
private:
    float real;
    float imag;

public:
    //Sets the given value as a complex number
    void set(float r, float i) {
        real = r;
        imag = i;
    }

    //Displays the complex number properly
    void disp() {
        if (imag >= 0) {
            std::cout << real << " + " << imag << "i";
        } else {
            std::cout << real << " - " << -imag << "i";
        }
        std::cout << std::endl;
    }

    //Adds this complex number to another and returns the sum
    Complex sum(Complex other) {
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }
};

class Distance {
private:
    int feet;
    float inches;

public:
    //Sets the value of the distance
    void set(int f, float i) {
        feet = f;
        inches = i;
    }

    //Shows the value of the distance
    void disp() {
        std::cout << feet << " feet " << inches << " inches" << std::endl;
    }

    //Adds this distance to another and returns the sum
    Distance add(Distance other) {
        Distance result;
        result.feet = feet + other.feet;
        result.inches = inches + other.inches;
        if (result.inches >= 12.0) {
            result.feet += static_cast<int>(result.inches) / 12;
            result.inches = std::fmod(result.inches, 12.0);
        }
        return result;
    }
};

class Time {
private:
    int hours;
    int minutes;

public:
    //Sets the time
    void settime(int h, int m) {
        hours = h;
        minutes = m;
    }

    //Shows the time
    void showtime() {
        std::cout << "Time: " << hours << " hours " << minutes << " minutes" << std::endl;
    }

    //Adds this time to another and returns the sum
    Time sum(Time other) {
        Time result;
        result.hours = hours + other.hours;
        result.minutes = minutes + other.minutes;
        if (result.minutes >= 60) {
            result.hours += result.minutes / 60;
            result.minutes %= 60;
        }
        return result;
    }
};


int main() {
    //7b
    std::cout << "Making first rectangle:\n";
    Rectangle firstRectangle;
    firstRectangle.setlength(5);
    firstRectangle.setwidth(2.5);
    firstRectangle.show();
    std::cout << "Making second rectangle:\n";
    Rectangle secondRectangle;
    secondRectangle.setlength(5);
    secondRectangle.setwidth(18.9);
    secondRectangle.show();
    //7c
    std::cout << "Equal area: " << firstRectangle.sameArea(secondRectangle);
    std::cout << "\n\nSetting first rectangle to 15x6.3";
    std::cout << "\nFirst rectangle:\n";
    firstRectangle.setlength(15);
    firstRectangle.setwidth(6.3);
    firstRectangle.show();
    std::cout << "Second rectangle:\n";
    secondRectangle.show();
    std::cout << "Equal area: " << firstRectangle.sameArea(secondRectangle);

    //8b
    Complex complex1, complex2, complex3;
    complex1.set(3.5, 210);
    complex2.set(3.4, 210);
    complex3 = complex1.sum(complex2);
    std::cout << "\n-----\nComplex Number 1: ";
    complex1.disp();
    std::cout << "Complex Number 2: ";
    complex2.disp();
    std::cout << "Sum of Complex Numbers 1 and 2: ";
    complex3.disp();

    //9b
    Distance distance1, distance2, distance3;
    distance1.set(5, 11);
    distance2.set(0, 10);
    distance3 = distance1.add(distance2);
    std::cout << "-----\nDistance 1: ";
    distance1.disp();
    std::cout << "Distance 2: ";
    distance2.disp();
    std::cout << "Sum of Distances 1 and 2: ";
    distance3.disp();

    //10b
    Time time1, time2, time3;
    time1.settime(5, 59);
    time2.settime(0, 10);
    time3 = time1.sum(time2);
    std::cout << "-----\nTime 1: ";
    time1.showtime();
    std::cout << "Time 2: ";
    time2.showtime();
    std::cout << "Sum of Times 1 and 2: ";
    time3.showtime();

    return 0;
}
