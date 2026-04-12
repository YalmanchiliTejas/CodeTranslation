#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
const int max_n = 1e5;
const ll mod = 1e9+7;
typedef long double ld;
ll rec(ll n, ll x){
  if(n == 0) return 1;
  ll len = (1LL<<(n+1)) - 3;
  ll num = (1LL<<n) - 1;
  if(x == 1) return 0;
  else if(x <= len + 1) return rec(n-1, x-1);
  else if(x == len + 2) return num + 1;
  else if(x <= (len+1)*2) return num + 1 + rec(n-1, x-len-2);
  else return num*2 + 1;
}
int main(){
  ll n;  cin >> n;
  ll x; cin >> x;
  cout << rec(n, x) << endl;
  return 0;
}
