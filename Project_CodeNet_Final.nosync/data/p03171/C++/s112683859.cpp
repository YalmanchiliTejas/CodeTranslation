#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define MOD 1000000007
ll power(ll a, ll b) { //a^b
	ll res = 1;
	while (b > 0) {
		if (b & 1) {res = (res * a); b--;}
		a = (a * a);
		b >>= 1;
	}
	return res;
}
ll n;
ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

ll dp[3001][3001][2];
vector <ll> v(3001);

ll solve(ll i,ll j,ll t){
	if(dp[i][j][t]!=10000000000000)
		return dp[i][j][t];
	if(i==j){
		return dp[i][j][t]=v[i]*(t%2==0?1:0);
	}
	if(t%2==0){
		dp[i][j][t]=max(v[i]+solve(i+1,j,1),v[j]+solve(i,j-1,1));
	}
	else{
		dp[i][j][t]=min(solve(i+1,j,0),solve(i,j-1,0));
	}
	return dp[i][j][t];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=0;i<2;i++){
		for(ll j=0;j<3001;j++){
			for(ll k=0;k<3001;k++)
				dp[j][k][i]=10000000000000;
		}
	}
	//cout<<dp[0][0][0]<<endl;
	cin>>n;
	ll sum=0;
	for(ll i=0;i<n;i++){
		cin>>v[i];
		sum+=v[i];
	}
	ll ans=solve(0,n-1,0);
	cout<<2*ans-sum<<"\n";
}