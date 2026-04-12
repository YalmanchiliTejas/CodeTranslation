#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD=998244353;
int n,s,a[3005];
ll f[3005][3005][2][2];

ll dp(int cur,int sum,bool open,bool close){
	if(cur==n) return (sum==s&&close==true)*1LL;
	if(sum>s) return 0;
	ll &res=f[cur][sum][open][close];
	if(~res) return res;
	res=0LL;
	if(close) (res+=dp(cur+1,sum,open,close))%=MOD;
	else if(!open){
		(res+=dp(cur+1,sum,false,false))%=MOD;
		(res+=dp(cur+1,0,true,false))%=MOD;
		(res+=dp(cur+1,a[cur],true,false))%=MOD;
		(res+=dp(cur+1,a[cur],true,true))%=MOD;
	}
	else{
		(res+=dp(cur+1,sum,open,close))%=MOD;
		(res+=dp(cur+1,sum+a[cur],open,close))%=MOD;
		(res+=dp(cur+1,sum,true,true))%=MOD;
		(res+=dp(cur+1,sum+a[cur],true,true))%=MOD;
	}
	return res;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>s;
	for(int i=0;i<n;++i) cin>>a[i];
	memset(f,-1,sizeof f);
	cout<<dp(0,0,false,false);
}