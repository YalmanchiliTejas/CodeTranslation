
// Problem : E - Sequence Sum
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// $%U%$
// Mere bas ka nahi hai
// still i'm trying
// apna time aayega
//
//        .--------------.  
//        | Try First One|
//        '--------------'
//                |     .--------------.
//                |     |              |
//                V     V              |
//              .--------------.       |
//              |      AC.     |<---.  |  
//              '--------------'    |  |
//              (True)|  |(False)   |  |
//           .--------'  |          |  |
//           |           V          |  |
//           |  .--------------.    |  |
//           |  |   Try Again  |----'  |
//           |  '--------------'       |
//           |                         |
//           |  .--------------.       |
//           '->| Try Next One |-------'
//              '--------------'                          		  
//
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll power(ll x,ll y,ll m){if(y==0)return 1;ll p=power(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll nCr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}
#define Test int t;cin>>t;while(t--)
#define endl '\n'
void solve()
{
	ll n,x,m;
	cin >> n >> x >> m;
	vector<ll> ans((int)1e5+10);
	map<ll,ll> mp;
	ans[0]=x;
	mp[x]=1;
	ll re,rs;
	int f=0;
	for(ll i=1;i<n;++i)
	{
		ans[i]=power(ans[i-1],2,m);
		if(mp[ans[i]]!=0)
		{
			re=i-1;
			rs=mp[ans[i]]-1;
			f=1;
			break;
		}
		mp[ans[i]]=i+1;
	}
	if(f==0)
	{
		ll fans=0;
		for(int i=0;i<n;++i)
		fans+=ans[i];
		cout << fans << endl;
		return;
	}
	vector<ll> sum(re+1);
	ll fans=0;
	for(ll i=0;i<=re;++i)
	{
		if(i==0)
		sum[i]=ans[i];
		else
		sum[i]=ans[i]+sum[i-1];
		if(i==rs-1)
		fans+=sum[i];
	}
	n-=rs;
	ll temp;
	if(rs-1>=0)
	temp=sum[re]-sum[rs-1];
	else
	temp=sum[re];
	ll len=(re-rs+1);
	fans+=(n/len)*temp;
	n%=len;
	for(ll i=rs;i<rs+n;++i)
	fans+=ans[i];
	cout << fans << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//Test
	solve();
	return 0;
}
