#include<bits/stdc++.h>
using namespace std;

int main(){
  string r, g, b;
  cin >> r >> g >> b;
  string A=r+g+b;
  int Ans=stoi(A);
  if(Ans%4==0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}