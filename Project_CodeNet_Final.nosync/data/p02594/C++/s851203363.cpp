#include <bits/stdc++.h>
#define endl '\n'
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back
#define ll long long
#define rep(i,n) for (i = 0; i < n; ++i) 
#define REP(i,k,n) for (i = k; i <= n; ++i) 
#define REPR(i,k,n) for (i = k; i >= n; --i)
using namespace std;
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);
int check(ll n)
{
  ll s=sqrt(n);
  if(s*s==n)
    return 1;
  else
    return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   //freopen("error.txt", "w", stderr); 
  freopen("output.txt", "w", stdout); 
#endif 
   
 ll T = 1 ;
 //cin>>T;
 for(ll t=1;t<=T;t++)
 {
  ll n;
  cin>>n;
  if(n>=30)
  cout<<"Yes";
  else
  cout<<"No";
 }

  return 0;
}
