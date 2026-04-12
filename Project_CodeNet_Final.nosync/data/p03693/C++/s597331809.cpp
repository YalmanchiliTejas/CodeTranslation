#include<iostream>
using namespace std;

int main(void){
  char input[3];
  cin >> input[0] >> input[1] >> input[2];
  int number = atoi(input);
  if(number%4 == 0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}