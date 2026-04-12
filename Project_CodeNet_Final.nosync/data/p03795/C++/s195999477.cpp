#include<iostream>
#include<string>
using namespace std;

int main(){
  int input;
  int harau;
  int morai;
  cin >> input;
  harau = input*800;
    morai = input/15;
    morai = morai*200;
  cout << harau-morai << endl;
  return 0;
}
