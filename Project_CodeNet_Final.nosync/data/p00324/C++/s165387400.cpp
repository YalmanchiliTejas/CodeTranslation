#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define all(r) (r).begin(),(r).end()
#define rall(r) (r).rbegin(),(r).rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

int main(){
	int n;
	cin>>n;
	vi d(n);
	rep(i, n) cin>>d[i];
	vl s(n+1);
	s[0] = 0LL;
	map<ll, int> m;
	int ans = 0;
	m[0LL] = 0;
	rep(i, n) {
		s[i+1] = s[i] + d[i];
		if(m.count(s[i+1])) ans = max(ans, i + 1 - m[s[i+1]]);
		else m[s[i+1]] = i+1; 
	}
	cout<<ans<<endl;
}