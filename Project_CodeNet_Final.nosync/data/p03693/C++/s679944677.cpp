#include <bits/stdc++.h>
#define For(i, begin, end) for(int i=begin;i<end;i++)
#define Rep(i, n) For(i,0,n)
#define Sort(v) sort(v.begin(),v.end())
using namespace std;

int main(){
  int r,g,b;
  cin>>r>>g>>b;
  if((10*g+b)%4==0)cout<<"YES";
  else cout<<"NO";

  return 0;
}