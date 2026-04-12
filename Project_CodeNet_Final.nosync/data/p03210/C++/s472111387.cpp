#include<iostream>
using namespace std;
int main(){
  int age;
  cin >> age;
  if(age!=1 && age!=9 && age%2!=0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
  
  return 0;
}