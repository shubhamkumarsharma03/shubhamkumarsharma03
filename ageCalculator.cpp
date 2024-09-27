// day difference from current and dob -> it tell 's our age
#include<iostream>
#include<ctime>
#include<string>
#include<vector>
using namespace std;
bool isLeapYear(int year) {
    // A year is a leap year if it is divisible by 4,
    // but not divisible by 100, unless it is also divisible by 400.
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}
class Date{
    int m;
    int d;
    int y;
public:
    Date(int d,int m,int y){
        this->m = m;
        if(1>m || m>12){
            cout<<"Invalid month"<<endl;
        }

        this->y = y;
        if(y<0){
            cout<<"Invalid year"<<endl;
        }

        this->d = d;
        if(isLeapYear(y) && m == 2 && (d>29 || d<1)){
            cout<<"Invalid date"<<endl;
        }
        if(!isLeapYear(y) && m == 2 && (d>28 || d<1)){
            cout<<"Invalid date"<<endl;
        }
        if((m<=7 && m%2 != 0) || (m>7 && m%2 == 0)){
            if(d>31 || d<1) cout<<"Invalid date"<<endl;
        }
        if((m!=2) && (m<=7 && m%2 == 0) || (m>7 && m%2 != 0)){
            if(d>30 || d<1) cout<<"Invalid date"<<endl;
        }
    }

    void display(){
        cout<<d<<" "<<m<<" "<<y<<endl;
    }

    int getDate(){
        return d;
    }
    int getMonth(){
        return m;
    }
    int getYear(){
        return y;
    }

};
void currAge(Date &d, Date &c){ // (dob,curr)
    int yr,mn,day;
    vector<int>arr(12,0);
        if(isLeapYear(c.getYear())){
        arr = {31,29,31,30,31,30,31,31,30,31,30,31};
    }
    else{
        arr = {31,28,31,30,31,30,31,31,30,31,30,31};
    }

    if((c.getMonth() > d.getMonth()) && (c.getDate() > d.getDate())){
        mn = c.getMonth() - d.getMonth();
        day = c.getDate() - d.getDate();
        yr = c.getYear() - d.getYear();
    }

    else if((c.getMonth() > d.getMonth()) && (c.getDate() < d.getDate())){
        yr = c.getYear() - d.getYear();
        mn = c.getMonth() - d.getMonth() - 1;
        day = arr[c.getMonth()-2] - d.getDate() + c.getDate();
    }

    else if((c.getMonth() < d.getMonth()) && (c.getDate() > d.getDate())){
        yr =  c.getYear() - d.getYear() - 1;
        mn = 12 - d.getMonth() + c.getMonth();
        day = c.getDate() - d.getDate();
    }

    else{ // (c.getMonth() < d.getMonth()) && (c.getDate() < d.getDate())
        yr = yr = yr = c.getYear() - d.getYear() - 1;
        mn = 12 - d.getMonth() + c.getMonth() - 1;
        day = arr[c.getMonth()-2] - d.getDate() + c.getDate();
    }

    cout<<yr<<" years "<<mn<<" month "<<day<<" days";

    
}

int main(){

    string currDate = __DATE__;
    int month,date,year;

    string currM = currDate.substr(0,3);
    if(currM == "Jan") month = 1;
    else if(currM == "Feb") month = 2;
    else if(currM == "Mar") month = 3;
    else if(currM == "Apr") month = 4;
    else if(currM == "May") month = 5;
    else if(currM == "Jun") month = 6;
    else if(currM == "Jul") month = 7;
    else if(currM == "Aug") month = 8;
    else if(currM == "Sep") month = 9;
    else if(currM == "Oct") month = 10;
    else if(currM == "Nov") month = 11;
    else month = 12;

    date = stoi(currDate.substr(4,2));
    year = stoi(currDate.substr(7,4));

    Date c(date,month,year);
    
    Date d(03,05,2005);
    

    currAge(d,c); // c-> current date and d-> dob

}