#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mset(m,v) memset(m,v,sizeof(m))
#define pr(a,s) printf("Case #%lld: %lld\n",a,s)
#define mod 1000000007
#define mp make_pair
#define all(a)                a.begin(),a.end()
#define pb push_back
#define scan(a) scanf("%d",&a)
#define scanl(a) scanf("%lld",&a)
#define se second
#define fi first
#define pi 3.14159265358979323
#define pii pair<ll,ll>

#define trace1(x)             cout <<#x<<": "<<x<< endl;
#define trace2(x, y)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)       cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e) cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;


const int MAXM = 2e5+3;
const ll inf = 1e15;

vector<int> v;
int n, d;
ll dp[MAXM][2][102];

ll recur(int idx,int tight, int sum)
{
	if (idx == n and sum == 0)	return 1LL;
	if (idx == n)	return 0LL;
	if (dp[idx][tight][sum] != -1)	return dp[idx][tight][sum];
	ll ret = 0;
	if (tight) {
		for (int i=0;i<v[idx];i++){
			ret += recur(idx+1, 0, (sum+i)%d);
			if (ret >= mod)	ret %= mod;
		}
		ret += recur(idx+1, 1, (sum+v[idx])%d);
		if (ret >= mod)	ret %= mod;
	} else {
		for (int i=0;i<10;i++){
			ret += recur(idx+1, 0, (sum+i)%d);
			if (ret >= mod)	ret %= mod;
		}
	}
	return dp[idx][tight][sum] = ret;
}

ll solve(string s, int d)
{
	mset(dp,-1);
	n = s.size();
	for (int i=0;i<n;i++){
		v.pb(s[i]-'0');
	}
	return recur(0, 1, 0);
}

int main()
{
	string s;
	cin>>s;
	cin>>d;
	cout << (solve(s, d) - 1 + mod)%mod << endl;
	return 0;	
}