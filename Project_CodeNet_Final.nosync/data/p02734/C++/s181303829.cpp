#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define all(x) 		 (x).begin(),(x).end()
#define mp     		 make_pair
#define pb 				 push_back
#define fi 				 first
#define se 				 second
#define sz(x) 		 ((int)(x).size())
#define rep(x,y,z) for(int x=y;x<z;x++)
#define per(x,z,y) for(int x=z-1;x>=y;x--)
#define trav(y,x)  for(auto& y:x)
#define pii 			 pair<int,int>
#define vi 				 vector<int>

int dbg = 0;
#define cri   		 if(1)
#define shame 		 cri cerr<<(++dbg)<<"\n\n";

// aaaaaaaaaaaaaaaa
const int N = 2e5 + 1;
const int lg = 20;
const ll mod = 998244353;

void solve() {
  int n, s;
  cin >> n >> s;
  vi a(n);
  rep(i, 0, n)
    cin >> a[i];

  ll x = 0;
  vector<ll> dpA(s + 1, 0); dpA[0] = 1ll;
  vector<ll> dpR(s + 1, 0); dpR[0] = 1ll;
  per(i, n, 0) {
    if (a[i] > s) continue;

    bool upd = 0;
    ll right = 0;
    per(j, s + 1, a[i] + 1) {
      if (dpA[j - a[i]]) {
        if (j == s) {
          upd = 1;
          right = dpR[j - a[i]];
        }

        dpA[j] += dpA[j - a[i]];
        dpA[j] %= mod;

        dpR[j] += dpR[j - a[i]];
        dpR[j] %= mod;
      }
    }
    if (a[i] == s) {
      upd = 1;
      right = n - i;
    }
    dpA[a[i]]++; dpA[a[i]] %= mod;
    dpR[a[i]] += (n - i); dpR[a[i]] %= mod;

    if (upd) {
      ll left = i + 1;
      ll add = (left * right) % mod;
      x += add; x %= mod;
    }
  }
  cout << x << "\n";
}

int main() {
  // freopen("input.in", "r", stdin);
  // freopen("input.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// cout<<setprecision(15);
	// int t; cin>>t; while(t--)
	solve();
	return 0;
}