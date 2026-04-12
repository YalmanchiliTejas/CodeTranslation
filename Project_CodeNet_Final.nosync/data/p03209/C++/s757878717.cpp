#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ITR(x,c) for(__typeof(c.begin() x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin() x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

#define lf double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

ll p[51], w[51];

ll rec(ll n, ll x)
{
	if (n == 0) return (x>0)?1:0;
	x--;
	if (x <= w[n-1]){
		return rec(n-1, x);
	}else{
		return p[n-1]+1+rec(n-1, x-w[n-1]-1);
	}
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, x; cin>>n>>x;
	p[0] = 1, w[0] = 1;
	rep(i, n){
		p[i+1] = 2*p[i]+1;
		w[i+1] = 2*w[i]+3;
	}
	ll ans=0;
	cout << rec(n, x) << "\n";
	return 0;
}