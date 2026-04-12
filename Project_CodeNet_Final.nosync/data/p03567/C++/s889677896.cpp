#include<iostream>
using namespace std;
int main(){
  string input;
  cin >> input;
  string tmp = "AC";
  int i =  (int)input.find(tmp);
  if (i == -1){
    cout << "No" << "\n";
  }else{
    cout << "Yes" << "\n";
  }
  return 0;
}
