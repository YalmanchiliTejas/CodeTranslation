#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n;i>0;i--)
#define rep1(i,s,n) for(int i=s;i<n;i++)
using namespace std;
typedef long long ll;

int main(){
   int n;
   cin >> n;
   vector<pair<ll,ll>> x(n);
   vector<ll> a(n),b(n);
   rep(i,n){
      cin >> a[i];
      x[i]=make_pair(a[i],i);
   }
   sort(x.begin(),x.end());
   rep(i,n) b[x[i].second]=i;
   rep(i,n){
      if(b[i]>=n/2) cout << x[n/2-1].first << endl;
      else cout << x[n/2].first << endl;
   }
}