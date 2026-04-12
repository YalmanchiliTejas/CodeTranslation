#include<bits/stdc++.h>
#include<cmath>
#define pb push_back
#define ld long double
#define mp make_pair
#define vl vector<ll> 
#define vd vector<double>
#define vld vector<long double>
#define ll long long int
#define pl pair<ll, ll>
#define all(a) a.begin(), a.end()
#define forr(i, n) for(ll i=0; i<n; i++) 
#define forr1(i, n) for(ll i=1; i<=n; i++)
using namespace std;
const ld PI =3.1415926535897923846;
const ll MOD = 1000000007;
const ll N=998244353;
ll power(ll x,ll n){ll res=1;while(n>0){if(n&1) res=res*x%MOD;x=x*x%MOD;n>>=1;}return res;}
ll modinverse(ll a){return power(a, MOD-2);}
void solve()
{
    ll n, x, m;
    cin>>n>>x>>m;
    map<ll, ll> mp1, pos;
    mp1[x]++;
    vl ans;
    ans.pb(x);
    pos[x]=0;
    ll dupl=0;
    for(ll i=0;; i++)
    {
    	ll ele=ans.back();
    	ele=(ele*ele)%m;
    	if(mp1.find(ele)!=mp1.end())
    	{
    		dupl=ele;
    		break;
    	}
    	mp1[ele]++;
    	pos[ele]=(i+1);
    	ans.pb(ele);
    }
    ll times=(n%(ll)ans.size());
    ll sum=0, kid=0;
    ll n2=(ll)ans.size();
    //cout<<ans.size()<<endl;
    if(ans.back()==0)
    {
    	forr(i, min((ll)ans.size(), n))
    		sum+=ans[i];
    	cout<<sum<<endl;
    	return;
    }
    for(ll i=pos[dupl]; i<(ll)ans.size(); i++)
    {
    	kid+=ans[i];
    }
    ll cycle_len=(n2-pos[dupl]);
    if(n<=(n2))
    {
    	ll sumsum=0;
    	forr(i, n)
    		sumsum+=ans[i];
    	cout<<sumsum<<endl;
    	return;
    }
    forr(i, pos[dupl])
    {
    	sum+=ans[i];
    	//cout<<ans[i]<<endl;
    }
    n-=(pos[dupl]);
    sum=sum+(n/cycle_len)*kid;
    times=(n%cycle_len);
    for(ll j=pos[dupl]; j<=pos[dupl]+times-1; j++)
    	sum+=ans[j];
    cout<<sum<<endl;
}
int main()
{
	#ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}