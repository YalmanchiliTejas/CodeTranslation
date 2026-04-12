#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define FOR(i,a,b) for(ull i=a;i<b;i++)
#define FORit(it,a) for(auto it=a.begin();it!=a.end();it++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define vec vector
#define vi vec<int>
#define vll vec<ll>
#define pb push_back
#define pp pop_back
#define all(x) x.begin(),x.end()
#define testcases ll t;cin>>t;while(t--)
#define mem(a,k) memset(a,k,sizeof(a))
#define FF first
#define SS second
#define MP(x,y) make_pair(x,y)
#define rt return
#define br break
#define ct continue
#define elif else if
#define ii pair<int,int>
#define vecin(a,n,index) for(int i=index;i<n;i++)cin>>a[i]
#define vecout(a,n,index) for(int i=index;i<n;i++)cout<<a[i]<<" ";cout<<endl;
//ll mod = 1000000007;
ll a[1000001] = {0};
unsigned long long int n, x, m;
void fun() {

	cin >> n >> x >> m;
	a[1] = x;
	FOR(i, 2, 1000001)a[i] = (a[i - 1] % m * a[i - 1] % m) % m;
}
void solve() {
	fun();
	map<ll, ll> visited;
	vll ns;
	vll cs;
	ll tmp = 0;
	FOR(i, 1, m + 1) {
		if (visited[a[i]] == 1) {
			tmp = a[i];
			br;
		}
		else {
			ns.pb(a[i]);
			visited[a[i]] = 1;
		}
	}
	ull S = ns.size();
	FOR(i, 0, S ) {
		if (ns[i] == tmp) {
			FOR(j, i, S)cs.pb(ns[j]);
			int k = S - i;
			while (k--)ns.pp();
			br;
		}
	}
	ull ans = 0, mine;
	if (n > ns.size())mine = ns.size(); else mine = n;
	FOR(i, 0, mine)ans += ns[i];
	n = n - mine;
	if (n) /*if(!n) Means if(n==0)*/
	{
		if (cs.size()) {
			if ((n / cs.size()))FOR(i, 0, cs.size())ans += cs[i] * (n / cs.size());
			if (n % cs.size())FOR(i, 0, n % cs.size())ans += cs[i];
		}

	}
	cout << ans << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	// START FROM HERE :)
	solve();
}