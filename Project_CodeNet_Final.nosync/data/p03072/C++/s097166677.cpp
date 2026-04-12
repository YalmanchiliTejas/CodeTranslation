#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin>>a;
  vector<int> b(a);
  for(int i=0;i<a;i++)
    cin>>b[i];
  int c=b[0],d=0;
  for(int i=0;i<a;i++){
    c=max(c,b[i]);
    if(b[i]>=c)
      d++;
  }
  cout<<d;
}