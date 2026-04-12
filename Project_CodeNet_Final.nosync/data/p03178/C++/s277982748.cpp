#include<bits/stdc++.h>
#define ll long long int
#define db long double
#define ull unsigned long long int
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
#define INF 1000000000
#define MOD 1000000007
#define MAXN 1000005
 
using namespace std;

string s;
ll d;
ll dp[10005][101][2];

ll recur(ll pos,ll rem,ll flag)
{
	if(pos==s.length())
	{
		if(rem==0) return 1;
		else return 0;
	}
	if(dp[pos][rem][flag]!=-1) return dp[pos][rem][flag];
	ll res=0,limit;
	if(flag==1) limit=9;
	else limit=s[pos]-'0';
	// cout<<"-->"<<limit<<"\n";
	for(ll i=0;i<=limit;i++)
	{
		ll newflag=flag,remain=rem;
		if(flag==0 && i<limit) newflag=1;
		// remain*=10;
		// remain+=i;
		// remain%=d;
		res+=recur(pos+1,(rem+i)%d,newflag);
		res%=MOD;
	}
	return dp[pos][rem][flag]=res;

}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int tests=1;
    // compute();
    // cin>>tests;
    while(tests--)
    {
    	ll i,j;
    	cin>>s;
    	cin>>d;
    	// cout<<s;
    	memset(dp,-1,sizeof(dp));
    	cout<<(recur(0,0,0)-1+MOD)%MOD;

    }
    	return 0;
    
}