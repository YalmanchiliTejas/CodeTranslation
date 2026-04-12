#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll, ll> P;

struct edge {int to, cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

ll GCD(ll a, ll b){
  if(b==0) return a;
  else return GCD(b, a%b);
}

ll LCM(ll a, ll b){
  if(a<b) swap(a,b);
  return a/GCD(a,b)*b;
}

int main(){
  int n;
  cin >> n;
  ll a[n];
  ll mod = 1e9+7;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  ll s[n];
  s[0] = a[0];
  for(int i=1; i<n; i++){
    s[i] = s[i-1]+a[i];
    s[i] %= mod;
  }
  ll ans = 0;
  for(int i=0; i<n-1; i++){
    ll tmp = s[n-1]-s[i];
    if(tmp<0) tmp += mod;
    ans += (a[i]*tmp)%mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
