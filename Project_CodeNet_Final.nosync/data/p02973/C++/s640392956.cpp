#include<bits/stdc++.h>
#include<bitset>


using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(ll i=st; i<ed; i++)
#define repn(i, st, ed) for(ll i=st; i<=ed; i++)
#define repb(i, ed, st) for(ll i=ed; i>=st; i--)
#define all(v) v.begin(),v.end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 1e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code
vector<ll> v;
multiset<ll> s;
int main()
{
	int n;
	cin>>n;
	ll x;
	cin>>x;
	s.insert(x);
	s.insert(M);
	ll ans = 1;
	rep(i, 1, n)
	{
		cin>>x;
		auto itr = s.lower_bound(x);
		if(itr == s.begin())
		{
			ans++;
			s.insert(x);
		}
		else
		{
			itr--;
			s.erase(itr);
			s.insert(x);
		}
		// for(int x: s) cout<<x<<" ";
		// cout<<endl;
	}
	
	cout<<ans<<endl;
}
