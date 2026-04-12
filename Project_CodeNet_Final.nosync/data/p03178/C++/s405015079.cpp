#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define N 1000000007
#define nmax 200001
#define pll pair<ll,ll>
#define fill_nums(A,n) for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);}

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
	if(a==0) {
		x = 0;
		y = 1;
		return b;
	}

	ll x1,y1;
	ll gcd = extended_gcd(b%a,a,x1,y1);

	x = y1 - (b/a)*x1;
	y = x1;

	return gcd;
}

int main() {
    
    string s; 
    ll d;

    cin>>s>>d;
    vector<vector<ll>> dp(s.length(), vector<ll>(d,0));
    ll sp = 0;

    for(ll i=0;i<s.length();i++) {
    	if(i==0) {
    		int a = s[0]-'0';
    		for(int b=0;b<=a;b++)
    			dp[0][b%d]++;
    		sp = a%d;
    		continue;
    	}

    	for(ll j=0;j<d;j++) {
    		for(ll k=0;k<=9;k++)
    			dp[i][(j+k)%d] = (dp[i][(j+k)%d] + dp[i-1][j])%N;
    	}


    	for(ll k=s[i]-'0'+1;k<=9;k++)
    		dp[i][(sp+k)%d] = (dp[i][(sp+k)%d] - 1 + N)%N;
    	sp = (sp + s[i]-'0')%d;
    }

    cout<<(dp[s.length()-1][0]-1+N)%N<<endl;
   	 	
	return 0;
}

