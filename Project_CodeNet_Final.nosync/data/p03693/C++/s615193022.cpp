#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
typedef long long int ll;


int main(){
  int r,g,b;
  cin>>r>>g>>b;
  if((g*10+b)%4 ==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}




