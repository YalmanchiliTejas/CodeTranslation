#include<bits/stdc++.h>
#include<bitset>


using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 1010;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code

ll len[51];
ll ps[51];

ll findans(ll x, int n)
{
	if(x <= 0) return 0;
	ll tlen = len[n];
	if(x >= tlen) return ps[n];
	ll ans = findans(x-1, n-1) + findans(x - (tlen/2) - 1, n-1);
	if(x > (tlen / 2))
		ans++;
	return ans;
}

int main()
{
	ll n, x;
	cin>>n>>x;
	len[0] = ps[0] = 1;
	repn(i, 1, 50)
	{
		len[i] = len[i-1]*2 + 3;
		ps[i] = ps[i-1]*2 + 1;
	}
	cout<<findans(x, n)<<endl;
}
