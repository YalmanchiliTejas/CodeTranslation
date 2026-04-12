#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pp pair<ll,ll>
#define vi vector<pair<pp,pp> >
#define pq_min priority_queue<ll,vector<ll>,greater<ll> >
#define pq_max priority_queue<ll>
#define forx(i,a,b) for(ll i=0;i<a;i++)
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define fill(a,b) memset((a),(b),sizeof((a)))
#define ld long double
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<pp,pp> ppll;
const ll mod=1e9 + 7;

string s;
ll k;
ll dp[100][4][2]; // dp[pos][check][count]
vector<ll> num;
ll call(ll pos,ll check,ll cnt)
{
	if(cnt>k) return 0;
	
	if(pos==num.size())
	{
		if(cnt==k) return 1;
		return 0;
	}
	
	if(dp[pos][cnt][check]!=-1) return dp[pos][cnt][check];
	
	ll res=0;
	ll limit;
	
	if(check==0) //digits we places so far is matches with the prefix of b (boundry)
	{
		 // so we place max digit is b[pos]
		 limit=num[pos];
	}
	else // the number is already become smaller than b so we can put any digit
	{
		limit=9;
	}
	
	/* Direct use range between a and b:
	ll l=0,r=9;
	
	if(big==0) l=xx[pos];
	if(small==0) r=yy[pos];
	
	for(ll i=l;i<=r;i++)
	{
		ll nbig=big;
		ll nsmall = small;
		
		if(i>l) nbig=1;
		if(i<r) nsmall=1;
	}
	*/
	
	for(ll digit = 0 ; digit <= limit ;digit++)
	{
		ll ncheck = check;
		ll ncnt = cnt;
		if(check==0 && digit < limit) ncheck=1; // the number is getting smaller at this position
		
		if(digit>0) ncnt++;
		if(ncnt <= k) res += call(pos+1 , ncheck , ncnt);
	}
	return dp[pos][cnt][check]=res;
}


ll solve()
{
	num.clear();
	for(ll i=0;i<s.length();i++)
	{
		num.pb(s[i]-'0');
	}
	memset(dp,-1,sizeof(dp));
	ll res=call(0,0,0);
	return res;	
}

int main()
{
	cin>>s>>k;
    ll res=solve();
    cout<<res;
	return 0;
}