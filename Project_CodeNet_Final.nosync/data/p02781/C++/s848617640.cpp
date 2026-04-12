#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define test ll t;cin>>t;while(t--)
#define input(a,b) vector<ll>v(b);for(auto i=a;i<b;i++)cin>>v[i]
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef unordered_map<ll,ll> mpp;
typedef pair<ll,ll> ii;
#define mod 100000007

vector<ll>v(102);
int dp[102][4][2];
int k;
int find(int pos,int cnt,int f)
{
	if(cnt>k)
		return 0;
	if(pos==v.size())
	{
		if(cnt==k)
			return 1;
		return 0;
	}
	if(dp[pos][cnt][f]!=-1)
	{
		return dp[pos][cnt][f];
	}
	int res=0;
	int LMT;
	if(f==0)
	{
		LMT=v[pos];
	}
	else
		LMT=9;
	
	for(auto dgt=0;dgt<=LMT;dgt++)
	{
		int nf=f;
		int ncnt=cnt;
		if(f==0&&dgt<LMT)
			nf=1;
		if(dgt!=0)
			ncnt++;
		if(ncnt<=k)
			res+=find(pos+1,ncnt,nf);
	}
	return dp[pos][cnt][f]=res;
}

int32_t main()
{
	fast;
	string s;
	cin>>s;
	cin>>k;
	v.resize(s.length());
	memset(dp, -1, sizeof(dp));
	for(auto i=0;i<s.length();i++)
	{
		v[i]=(int)(s[i]-48);
	}
	
	cout<<find(0,0,0)<<endl;
	

	return 0;
}