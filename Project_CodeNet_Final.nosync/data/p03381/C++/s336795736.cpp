#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(obj) (obj).begin(),(obj).end()

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;cin>>n;
  vector<ll> x(n),cp(n);
  rep(i,n)cin>>x[i];
  rep(i,n)cp[i]=x[i];
  sort(all(cp));
  ll l=cp[n/2-1],r=cp[n/2];
  rep(i,n){
      if(x[i]<=l)cout<<r<<endl;
      else cout<<l<<endl;
  }
  return 0;
  }
