#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=a; i<ll(b); i++) 
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int gcd(int a, int b){ //a>=0,b>=0,￢(a=b=0)
  while(min(a,b)>0){if(a<b)swap(a,b);a=a%b;}return max(a,b);
}
//int:~2e9   小数:double
int main(){
  int n,m;
  cin >>n>>m;


  if(n==m) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
