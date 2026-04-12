#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define all(c) (c).begin(),(c).end()
#define F first
#define S second
#define fast ios:: sync_with_stdio(false),cin.tie(nullptr);
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;

const int inf = 1e9;
const int inf64 = 1e18;
const int MOD = inf + 7;
const ld PI = acos(-1.0);
int dp[102][5][2];
int n,k;
vector<int> v;

int solve(int id , int tot , int ok)
{
	if(tot > k) return 0;
	if(id == n) return (tot == k);
	
	int ans = dp[id][tot][ok];
	if(ans != -1)
		return ans;
		
	ans = 0;
	int l = 0;
	int r = 9;
	
	if(ok) r = v[id];
	
	for(int i=l ; i<=r ; i++)
	{
		if(ok && i == v[id])
		{
			ans += solve(id + 1 , tot + (i != 0) , 1);
		}
		else
			ans += solve(id + 1 , tot + (i != 0) , 0);
	}

	dp[id][tot][ok] = ans;
	return ans;
}
int32_t main(){
	fast;
	memset(dp , -1 , sizeof(dp));
	
	string s;
	cin >> s;
	
	 n = s.length();
	v.resize(n);
	
	f(i,0,n)    v[i] = s[i] - '0';
	
	cin >> k;
	
	cout << solve(0,0,1);
}

