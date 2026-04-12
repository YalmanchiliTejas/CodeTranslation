#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define pll pair<long long,long long>
#define pdd pair<long double,long double>
#define vll vector<ll>
#define rep(i,j,n) for(int i=j;i<n;i++)
#define mp make_pair
#define pb push_back
#define pf push_front
#define inf 1e17
priority_queue<pll,vector<pll>,greater<pll> >pq;
priority_queue<ll,vector<ll>,greater<ll> >pq1;

string s;
ll d;
ll dp[200010][210][2];



ll solve(ll i,ll s1,ll p){
	if(dp[i][s1][p] != -1)
		return dp[i][s1][p];
	if(i >= (s.size())){
		if(s1 == 0)
			return 1;
		else
			return 0;
	}
	ll ans=0;
	if(p==1){
		for(int j=0;j<(s[i]-'0');j++){
			ans = (ans + solve(i+1,(s1+j)%d,0)) % mod;
		}
		ans = (ans + solve(i+1,(s1+s[i]-'0'+d)%d,1)) % mod;
	}
	else{
		for(int j=0;j<=9;j++){
			ans = (ans + solve(i+1,(s1+j)%d,0)) % mod;
		}
	}
	return dp[i][s1][p] = ans % mod;
}

int main(){
	if(fopen("input.txt", "r"))
	freopen("input.txt", "r", stdin),
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s>>d;
    for(int i=0;i<210;i++){
    	for(int j=0;j<200010;j++){
    		dp[j][i][0] = -1;
    		dp[j][i][1] = -1;
    	}
    }
    cout << (solve(0,0,1) - 1+mod)%mod;

    // for(int i=0;i<10;i++){
    // 	for(int j=0;j<10;j++){
    // 		cout << dp[i][j] << " ";
    // 	}
    // 	cout << "\n";
    // }
    return 0;
}
