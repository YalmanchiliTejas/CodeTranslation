#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,ans=0;cin >> n;ll a[n];
  rep(i,n)cin >> a[i];
  sort(a,a+n);ll u[n];u[0]=a[0];ll y = n/2-1;
  rep(i,n-1)u[i+1]=u[i]+a[i+1];
  if(n%2==0){
    cout << (u[n-1]*2-u[y]-u[y+1])-(u[y]*2-a[y]) << endl;
  }
  else {
    cout << max(u[n-1]*2-u[y]*2-a[y+1]-a[y+2]-u[y]*2,
                u[n-1]*2-u[y+1]*2-u[y+1]*2+a[y]+a[y+1]) << endl;
  }
}