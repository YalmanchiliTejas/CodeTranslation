#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

int n,s;
vector<int> a;
ll mod = 998244353;

ll dp[3100][3100][2];

ll f(int i, int s, int fir){
	if(s<0){
		return 0;
	}
	if(s==0){
		// cout<<n<<" "<<i<<endl;
		return n-i+1;
		// return 1;
	}
	if(i==n){
		return 0;
	}
	if(dp[i][s][fir] != -1){
		return dp[i][s][fir];
	}

	ll ans =0;

	ans += f(i+1,s,fir);
	ans %= mod;
	// ans += f(i+1,s-a[i],fir);
	// ans %= mod;

	if(fir){
		ans += (i+1)*f(i+1,s-a[i],0);
		ans %= mod;
	}
	else{
		ans += f(i+1,s-a[i],0);
		ans %= mod;
	}
	dp[i][s][fir] = ans;
	return ans;
}

int main(){
	fastread;
	cin>>n>>s;
	a.resize(n);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	cout<<f(0,s,1)<<endl;

	return 0;
}
