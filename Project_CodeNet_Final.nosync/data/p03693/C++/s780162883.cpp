#include <bits/stdc++.h>
#include <climits>
#include <math.h>
using namespace std;

int main(){
  char A, B, C;
  int D;
  string s="";
  cin >> A >> B >>C;
//  cout << A << endl;
//  cout << B << endl;
//  cout << C << endl;

  s+=A;
  s+=B;
  s+=C;

//  cout << s << endl;

  D = stoi(s);

//  cout << D << endl;
  if(D%4==0){
    cout << "YES"<<endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
