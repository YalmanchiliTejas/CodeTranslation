#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

int main(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi ans(n);
	int f = 0, b = n;
	reverse(all(a));
	rep(i, n) {
		if(i & 1) {
			ans[--b] = a[i];
		}else{
			ans[f++] = a[i];
		}
	}
	rep(i, n) {
		if(i != 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
