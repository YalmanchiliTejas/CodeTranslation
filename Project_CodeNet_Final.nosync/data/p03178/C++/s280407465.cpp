#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}


int dp[10002][102][2];
string k;
int d;

int solve(int pos,int sum,bool tight){

	if(pos == k.size()){
		return sum%d == 0;
	}
	if(dp[pos][sum][tight] != -1) return dp[pos][sum][tight];

	int end = (tight)?k[pos] - '0' : 9;
	int ans = 0;

	for(int i=0;i<=end;i++){
		ans = (ans + solve(pos+1,(sum+i)%d,tight&(i == end)))%mod;
	}

	return dp[pos][sum][tight] = ans;


}



int32_t main(){
	fastIO
	start();

	memset(dp,-1,sizeof(dp));
	cin>>k;
	cin>>d;

	cout<<(solve(0,0,1)-1 + mod)%mod<<endl;

	// it is said that we need more heads than tails so i 
	// opted for n+1/2 heads

}