#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

#define pvec(v) for(auto e: v) cout << e << " ";
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b) for(int i = (a); i<(b); ++i)
#define pb push_back
#define INF 1000000005
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define mod 998244353

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

ll power(ll x, ll y, ll p = MOD){  
  ll res = 1LL; 
  x = x % p;
  if (x == 0) return 0;
  while (y > 0){
    if (y & 1LL)  
      res = (res*x) % p;
    y = y>>1LL; 
    x = (x*x) % p;  
  }  
  return res;  
}  

int main(){
	// IO
	ll n, m, x;
	cin >> n >> x >> m;

	ll count[m + 1] = {0};
	count[x%m] = 1;
	ll prev = x, curr;

	vector<ll> cycle;
	ll sum = x;
	cycle.push_back(x);
	int cycle_point = -1, iter = 1;
	while(iter < n) {
		curr = power(prev, 2, m);
		if(count[curr]) {
			cycle_point = curr;
			break;
		}
		++count[curr];
		cycle.push_back(curr);
		sum+=curr;

		prev = curr;
		++iter;
	}
	if(iter == n || cycle_point == 0) {
		cout << sum << endl;
	}
	else {
		// cout << "NAH\n";
		ll len = (ll)cycle.size(), cl = 0;
		int i;
		for(i = 0; i < len; ++i) {
			if(cycle[i] == cycle_point) {
				break;
			}
		}
		ll add = 0LL;
		for(int j = i; j < len; ++j) {
			++cl;
			add+=cycle[j];
		}

		sum = sum + ((n - len)/cl)*add;
		int left = (n - len)%cl;
		for(int j = i; left; ++j) {
			sum+=cycle[j];
			--left;
		}

		cout << sum << endl;
	}
	


	return 0;
}