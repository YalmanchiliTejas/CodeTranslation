#include <bits/stdc++.h>
using namespace std;


int main() {
  int a,b,c,d,sum,ans;
  string s;
  cin>>a>>b>>c;
  ans=0;
  
  vector<int> vecV(a);
  vector<int> vecC(a);
  
  a = a-c;
  a= a/(b+c);
  cout<<a<<endl;
  return 0;
}
