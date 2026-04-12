#include<iostream>
#include<string>
using namespace std;

int main(){
  int age;
  cin >> age;
  if(age == 3 || age == 5 || age == 7){
    cout << "YES";
    return 0;
  }else{
    cout << "NO";
    return 0;
  }
}