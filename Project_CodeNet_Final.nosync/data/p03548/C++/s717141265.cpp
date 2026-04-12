#include<iostream>
using namespace std;
int main(){
  int X,Y,Z; cin >> X >> Y >> Z;
  int num=0,sum=0;
  sum += Z; 
  while(sum+Y+Z<=X){
    num++;
    sum += Y+Z;
  }
  cout << num << endl;
  return 0;
}
    