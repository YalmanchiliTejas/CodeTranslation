#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define REP(i,f,n) for(int i=f; i<(n); i++)
int main()
{
  ll ans = 0;
  ll n;
  cin >> n;
  vector<ll> a;
  ll b = 0, imamade = 0;

  REP(i,0,n){
    int d;
    cin >> d;
    d%=mod;
    a.push_back(d);
    b+=d;
    b%=mod;
  } 

  REP(i,0,n-1){
    imamade += a[i];
    imamade %= mod;
    //cout << (b- imamade)<< ", " <<a[i] << endl;
    ans += (a[i]*(b+mod- imamade)%mod)%mod;
    ans%=mod;
  }

  cout << ans%mod << endl;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}