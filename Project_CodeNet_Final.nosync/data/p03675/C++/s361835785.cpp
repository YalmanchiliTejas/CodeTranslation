#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
typedef vector<int> vi;
const int inf = 1e9+7;
const int INF = 1e18+7;
//26

deque<int> q;
int a[200000];
string str;
signed main(){
	int n;
	scanf("%lld", &n);
	rep(i,n)scanf("%lld", &a[i]);
	int b = 0;
	if(n%2 == 1)b = 1;
	rep(i,n){
		if(i%2 == b)q.push_back(a[i]);
		else q.push_front(a[i]);
	}
	rep(i,n){
		str += to_string(q.front());
		str.push_back(i == n-1 ? '\n' : ' ');
		q.pop_front();
	}
	cout << str;
	return 0;
}



