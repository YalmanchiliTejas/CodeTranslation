#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  int A,B;
  cin >> S;
  A = S.find("A");
  B = S.find("B");
  if(A >= 0 && B >= 0){
  	cout << "Yes" << endl;
  }else{
  	cout << "No" << endl;
  }
}