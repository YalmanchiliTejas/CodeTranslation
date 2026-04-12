#include <bits/stdc++.h>
#define For(i, begin, end) for(int i=begin;i<end;i++)
#define Rep(i, n) For(i,0,n)
#define Sort(v) sort(v.begin(),v.end())
using namespace std;

int main(){
  int X,Y,Z;cin>>X>>Y>>Z;
  cout<<(X-Z)/(Y+Z);

  return 0;
}