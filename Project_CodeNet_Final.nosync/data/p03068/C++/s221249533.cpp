#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,c;
  string b;
  cin>>a>>b>>c;
  char d=b.at(c-1);
  for(int i=0;i<a;i++){
    if(b.at(i)==d){
      cout<<d;
    }
    else{
      cout<<'*';
    }
  }
  cout<<endl;
}