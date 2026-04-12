#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define tll tuple<ll, ll, ll>
#define all(c) c.begin(),c.end()

const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;

ll h[50];
ll p[50];

ll calc(ll n, ll x){
  if (n == 0) return 1;
  if (x == 1) return 0;
  if (1 < x && x <= h[n-1]+1) return calc(n-1, x-1);
  if (x == h[n-1]+2) return p[n-1] + 1;
  if (h[n-1]+2 < x && x <= 2*h[n-1]+2) return p[n-1] + 1 + calc(n-1, x-h[n-1]-2);
  if (x == 2*h[n-1]+3) return 2*p[n-1] + 1;
  //if (n==0){
  //  if (x <= 0) return 0;
  //  else return 1;
  //}
  //else if (x <= h[n-1]+1) return calc(n-1, x-1);
  //else return p[n-1] + 1 + calc(n-1, x-h[n-1]-2);
}

int main() {
  ll n, x;
  cin >> n >> x;
  h[0] = 1;
  p[0] = 1;
  for(int i=1;i<=50;i++){
    h[i] = 2*h[i-1] + 3;
    p[i] = 2*p[i-1] + 1;
  }
  
  ll ans = calc(n,x);
  cout << ans << endl;
}