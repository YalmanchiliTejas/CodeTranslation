#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  ll n,ans=0;
  cin >> n;
  ll k[n];
  rep(i,n)cin >> k[i];
  sort(k,k+n);
  ll u[n];
  u[0]=k[0];
  rep(i,n-1)u[i+1]=u[i]+k[i+1];
  if(n%2==0){
    ll y=n/2-1;
    cout << (u[n-1]*2-u[y]-u[y+1])-(u[y]*2-k[y]) << endl;
  }
  else {
    ll y=n/2-1;
    cout << max((u[n-1]*2-u[y]*2-k[y+1]-k[y+2])-(u[y]*2),(u[n-1]*2-u[y+1]*2)-(u[y+1]*2-k[y]-k[y+1])) << endl;
  }
}
