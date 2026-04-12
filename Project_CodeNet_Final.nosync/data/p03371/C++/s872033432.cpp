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

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 1010;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code
int main()
{
	ll a, b, c,x, y;
	cin>>a>>b>>c>>x>>y;
	if(2*c > (a+b))
	{
		cout<<a*x+y*b<<endl;
	}
	else
	{
		ll z =min(x, y);
		ll ans = z*c*2;
		x -= z, y -= z;
		if(x == 0)
		{
			ll l = y*c*2;
			l = min(l, y*b);
			cout<<(ans+l)<<endl;
		}
		else
		{
			ll r = x*c*2;
			r = min(r, x*a);
			cout<<(ans+r)<<endl;
		}
	}
}
