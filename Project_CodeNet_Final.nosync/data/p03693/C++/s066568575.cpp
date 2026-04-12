#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if ((a*100+b*10+c)%4) NO;
  else YES;
  return 0;
}
