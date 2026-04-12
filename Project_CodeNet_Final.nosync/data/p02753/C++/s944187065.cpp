#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF (1e10+5)
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define FRL(i,a,n) for(i=a;i<n;i++)
#define FR(i,n) FRL(i,0,n)
#define RFRL(i,n) for(i=n;i>=0;i--)
#define MOD 1000000007
#define fill(a) memset(dp,a,sizeof(dp));

using namespace std;

typedef long long int  ll;

typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector< pair<ll,ll> > vpi;
typedef set<ll> st;
typedef map<ll,ll> mp;
typedef unordered_map<ll,ll> ump;

template< class T>
T minn(T a,T b)
{
	return (a>b)?b:a;
}
template< class T>
T maxx(T a,T b)
{
	return (a>b)?a:b;
}


void FILE_OP()
{
	#ifndef ONLINE_JUDGE
        freopen("inputf.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif
}
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void SOLVE()
{

	
	ll tt,m,i,j,k,a,b,c,d,l,r;
	//cin>>tt;
	tt=1;
	//fill(-1)
	ll n,W;
    
    //ll dp[100010];
	while(tt--)
	{
		string s;
		cin>>s;
		l=s.length();
		a=0;
		b=0;
		for(i=0;i<l;i++)
		{
			if(s[i]=='B')
				a++;
			if(s[i]=='A')
				b++;
		}
		if(a==l || b==l)
			cout<<"No\n";
		else
			cout<<"Yes\n";
		
	}


		
}

int main()
{
	FAST_IO
//FILE_OP();
	SOLVE();
	
	return 0;
}
