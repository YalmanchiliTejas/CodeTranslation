#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<(int)n ; i++)
#define rf(i,n,a) for(int i=n ; i>=a ; i--)
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()
#define fill(a,v) memset(a,v,sizeof(a))
#define d1(a) cout << a << "\n"
#define d2(a,b) cout << a << " " << b << "\n"
#define d3(a,b,c) cout << a << " " << b << " " << c << "\n"
#define d4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << "\n"
#define fast ios:: sync_with_stdio(false),cin.tie(nullptr);

typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;

const int inf = 1e9;
const int inf64 = 1e18;
const int MOD = inf + 7;
const int N = 2e5 + 5;
int a[N];
int n;
map<pii , int> dp;
int solve(int id , int need){
	if(need == 0)	return 0;
	if(need > (n - id + 2)/2 || id > n)	return -inf64;
	if(dp.find({id , need}) != dp.end())	return dp[{id , need}];
	int res = -inf64;
	res = max(res , solve(id + 1 , need));
	res = max(res , solve(id + 2 , need - 1) + a[id]);
	dp[{id , need}] = res;
	return res;
}
int32_t main(){
	fast;
	cin >> n;
	for(int i=1 ; i<=n ; i++){
		cin >> a[i];
	}		
	int ans = solve(1 , n/2);
	cout << ans;
}