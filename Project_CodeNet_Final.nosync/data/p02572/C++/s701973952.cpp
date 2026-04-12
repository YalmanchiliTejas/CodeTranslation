//Author - Soumik Roy
//Date & Time - August 29, 2020 6:16 PM
//Problem name - C - Sum of product of pairs
//Problem url - https://atcoder.jp/contests/abc177/tasks/abc177_c
//Time limit - 2000 ms
//Memory Limit - 1024 MB    

#include<bits/stdc++.h>
#define ll                    long long int
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define vi                    vector<int>
#define vll                   vector<ll>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define eb                    emplace_back
#define ull                   unsigned long long
#define bug(x)				  cout<<"  [ "#x<<" = "<<x<<" ]"<<endl;
#define KAMEHAMEHA            ios_base::sync_with_stdio(0);
#define RASENGAN              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int dir[]={0,1,0,-1,1,0,-1,0};
const ll MOD=1e9+7;
ll modInverse(ll n,ll p)
{
	if(p==0)
		return 1;
	ll x=modInverse(n,p/2)%MOD;
	x=(x*x)%MOD;
	if(p%2)
		x=(x*n)%MOD;
	return x%MOD;
}
void solve()
{
	ll n;
	cin>>n;
	ll sumofsquare=0,squareofsum=0;
	for(ll i=0,temp;i<n;i++)
	{
		cin>>temp;
		squareofsum=(temp+squareofsum)%MOD;
		ll sq=(temp*temp)%MOD;
		sumofsquare=(sumofsquare+sq)%MOD;
	}
	squareofsum=squareofsum*squareofsum;
	ll ans=(squareofsum-sumofsquare+MOD)%MOD;
	ll inmod=modInverse(2,MOD-2);
	//cout<<inmod<<endl;
	ans=(ans*inmod)%MOD;
	cout<<ans<<endl;
}
int main()
{
    KAMEHAMEHA
	int t=1;
	//cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		solve();
	}
    return 0;
}

