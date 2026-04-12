#include<bits/stdc++.h>
#include<stdint.h>

using namespace std;


#define MOD 1000000007
#define ll long long int
#define ff first
#define ss second
#define N 100001


template <typename T,typename G>
ostream& operator << (ostream& out, const pair<T,G> &a) 
{return out<<"( "<<a.ff<<", "<<a.ss<<")";}

template <typename T>
ostream& operator << (ostream& out, const vector<T> &a) 
{out<<"[ ";for(const auto &i:a)out<<i<<", ";return out<<"]"<<endl;}

template <typename T>
ostream& operator << (ostream& out, const set<T> &a) 
{out<<"{ ";for(const auto &i:a)out<<i<<", ";return out<<"}"<<endl;}

template <typename T,typename G>
ostream& operator << (ostream& out, const map<T,G> &a) 
{out<<"< ";for(const auto &i:a)out<<i<<", ";return out<<">"<<endl;}
ll dp[100009][2][101];
string s;
ll k,n;
ll getSum(ll pos,ll mod,bool flag)
{
	if(dp[pos][flag][mod]!=-1)
		return dp[pos][flag][mod];
	if(pos>=n)
	{
		if(mod==0)
			return 1;
		return 0;
	}
	int lim=9;
	if(!flag)
		lim=s[pos]-'0';
	ll ans=0;
	for(int i=0;i<=lim;i++)
	{
		if(flag || i<lim)
			ans=(ans%MOD+getSum(pos+1,(mod%MOD+i%MOD)%k,true)%MOD)%MOD;
		else
			ans=(ans%MOD+getSum(pos+1,(mod%MOD+i%MOD)%k,false)%MOD)%MOD;
	}
	return dp[pos][flag][mod]=ans%MOD;
}
void solve()
{
	cin>>s;
	cin>>k;
	n=s.length();
	memset(dp,-1,sizeof(dp));

	ll ans=(getSum(0,0,0))%MOD;
	ans--;
	if(ans<0)
		ans=MOD-1;
	cout<<ans<<"\n";
}
	


int32_t main()
{
 
    //your code goes here...
    int t=1;
   // cin>>t;
    while(t--)
    {
        solve();
    }    
}