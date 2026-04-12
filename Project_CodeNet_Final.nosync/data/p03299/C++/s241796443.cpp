#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
inline int add(int x,int y){
	return (x+y)%mod;
}
inline int mul(int x,int y){
	return (ll)x*y%mod;
}
inline int qpow(int base,int pw){
	if(pw<0) return 1;
	int res=1;
	while(pw>0){
		if(pw&1) res=mul(res,base);
		base=mul(base,base);
		pw>>=1;
	}
	return res;
}
int h[110],dp[110][110];
vector<int> hs;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",h+i);
		hs.push_back(h[i]);
	}
	hs.push_back(0);
	sort(hs.begin(),hs.end());
	hs.erase(unique(hs.begin(),hs.end()),hs.end());
	for(int i=1;i<=n;i++)
		h[i]=lower_bound(hs.begin(),hs.end(),h[i])-hs.begin();
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=h[i]+1;j<=h[i-1];j++)
			dp[i][0]=add(dp[i][0],add(dp[i-1][j],dp[i-1][j]));
		dp[i][0]=add(dp[i][0],add(dp[i-1][0],dp[i-1][0]));
		for(int j=1;j<=h[i];j++){
			dp[i][j]=mul(dp[i-1][j],qpow(2,hs[h[i]]-hs[h[i-1]]));
			if(h[i-1]>=j) continue;
			if(j>1) dp[i][j]=add(dp[i][j],mul(add(dp[i-1][0],dp[i-1][0]),mul(add(qpow(2,hs[j]-hs[j-1])-1,mod),qpow(2,hs[h[i]]-hs[j]))));
			else dp[i][j]=add(dp[i][j],mul(dp[i-1][0],mul(add(qpow(2,hs[j])-2,mod),qpow(2,hs[h[i]]-hs[j]))));
		}
	}
	int ans=0;
	for(int i=0;i<(int)hs.size();i++)
		ans=add(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}