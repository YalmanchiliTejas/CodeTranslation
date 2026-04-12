#include <bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)

typedef long long ll;

int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);

 ll n,k;
  cin >> n >> k;
  ll res=0;
  if(k==0) res-=n;
  
  rep(b,1,n+1){
   ll p=n/b;
   ll r=n-p*b;
    res+=p*max(0ll,b-k);
    res+=max(0ll,r-k+1);
  }
  
 cout << res << endl;
  
}
