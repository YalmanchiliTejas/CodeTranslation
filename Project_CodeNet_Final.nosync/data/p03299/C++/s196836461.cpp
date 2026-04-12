#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e2+10,mod=1e9+7;
int n,h[maxn],cnt;
int dp[maxn][2],l[maxn],r[maxn],a[maxn],b[maxn];
vector<int> ch[maxn];

void dfs(int pos){
	b[pos]=*min_element(h+l[pos],h+r[pos]+1);
	for(int i=l[pos],j;i<=r[pos];++i){
		if(h[i]==b[pos])
			continue;
		j=i;
		while(j<r[pos]&&h[j+1]>b[pos])
			++j;
		++cnt;
		l[cnt]=i,r[cnt]=j,a[cnt]=b[pos];
		ch[pos].push_back(cnt);
		dfs(cnt);
		i=j;
	}
}
inline ll fpow(ll a,ll n){
	ll res=1;
	for(;n;n>>=1,a=a*a%mod)
		if(n&1ll)
			res=res*a%mod;
	return res;
}
void solve(int pos){
	if(ch[pos].empty()){
		dp[pos][1]=fpow(2,b[pos]-a[pos]);
		dp[pos][0]=(fpow(2,r[pos]-l[pos]+1)+mod-2)%mod;
		return;
	}
	ll tmp[2],temp[2];
	for(int i=l[pos],j=0;i<=r[pos];)
		if(j<ch[pos].size()&&i==l[ch[pos][j]]){
			solve(ch[pos][j]);
			if(i==l[pos]){
				tmp[0]=dp[ch[pos][j]][0];
				tmp[1]=dp[ch[pos][j]][1]*2%mod;
			}
			else{
				temp[0]=(tmp[0]*dp[ch[pos][j]][0]+tmp[0]*dp[ch[pos][j]][1]*2+tmp[1]*dp[ch[pos][j]][0]+tmp[1]*dp[ch[pos][j]][1])%mod;
				temp[1]=tmp[1]*dp[ch[pos][j]][1]%mod;
				tmp[0]=temp[0];
				tmp[1]=temp[1];
			}
			i=r[ch[pos][j]]+1;
			++j;
		}
		else{
			if(i==l[pos]){
				tmp[0]=0;
				tmp[1]=2;
			}
			else{
				temp[0]=(tmp[0]*2+tmp[1])%mod;
				temp[1]=tmp[1];
				tmp[0]=temp[0];
				tmp[1]=temp[1];
			}
			++i;
		}
	dp[pos][0]=tmp[0];
	dp[pos][1]=tmp[1]*fpow(2,b[pos]-a[pos]-1)%mod;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>h[i];
	++cnt;
	l[1]=1,r[1]=n,a[1]=0;
	dfs(1);
	solve(1);
	cout<<(dp[1][0]+dp[1][1])%mod<<endl;
	return 0;
}