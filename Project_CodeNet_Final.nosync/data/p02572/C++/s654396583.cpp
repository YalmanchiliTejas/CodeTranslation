#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define piii pair<pii,pii>
#define precise cout<<fixed<<setprecision(10)
#define st first
#define nd second
#define ins insert
#define vi vector<int>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int mod=1e9+7;
const int MAX=2e5+5;
int a[MAX];
int suf[MAX];
int ans=0;
int32_t main(){
  BOOST;
  int n;
  cin>>n;
  for (int i=1;i<=n;i++)cin>>a[i];
  suf[n+1]=0;
  for (int i=n;i>=1;i--){
    suf[i]=(suf[i+1]+a[i])%mod;
  }
  
  for (int i=1;i<=n;i++){
   ans=(ans+a[i]*suf[i+1])%mod; 
  }
  
  cout<<ans;
  return 0; 
}
