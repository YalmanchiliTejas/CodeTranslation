#include <bits/stdc++.h>
using namespace std;

int main () {
  int A,B,C;
  cin>>A>>B>>C;
  int sum = B*10+C;
  if(sum%4==0){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}