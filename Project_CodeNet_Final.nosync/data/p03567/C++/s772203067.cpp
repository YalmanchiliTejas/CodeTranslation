#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  b="No";
  cin>>a;
  for(int i=0;i<a.size()-1;i++){
    if(a.at(i)=='A' && a.at(i+1)=='C'){
      b="Yes";
    }
  }
  cout<<b<<endl;
}