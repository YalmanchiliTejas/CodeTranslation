#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define REP(i,a,b) for(int i=a; i<b; i++)

const int MX=1e2+3;

ll n, k, dp[MX], p[MX], ans;

void pre();

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	pre();
	while(k){
		if(k>=dp[n]){
			ans+=p[n], k=0;
			break;
		}
		else if(k-1<dp[n-1]){
			n--, k--;
			continue;
		}
		else if(k==dp[n-1]+1){
			ans+=p[n-1];
			k=0;
			break;
		}
		else{
			ans+=p[n-1]+1;
			k-=dp[n-1]+2;
			n--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

void pre(){
	dp[0]=p[0]=1;
	REP(i,1,n+1) p[i]=p[i-1]*2+1, dp[i]=dp[i-1]*2+3;
}