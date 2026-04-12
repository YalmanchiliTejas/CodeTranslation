#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll MOD=1e9+7;
ll mypow(int x){
	ll res=1,ans=2;
	while (x>0){
		if (x%2==1){
			x--;
			res*=ans;
			res%=MOD; 
			continue;
		}
		ans*=ans;
		ans%=MOD;
		x/=2;
	}
	return res;
}
int n,a[103];
ll dp[103][103],ans=0;
vector<int>v;
map <int,int> vis;
map <int,int> mp;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (vis[a[i]]) continue;
		v.push_back(a[i]);
		vis[a[i]]=1;
	}
	v.push_back(0);
	sort (v.begin(),v.end());
	for (int i=0;i<v.size();i++)
		mp[v[i]]=i;
	dp[1][0]=(mypow(v[1]-v[0])-2)%MOD*mypow(a[1]-v[1])%MOD;
	for (int i=1;i<mp[a[1]];i++) dp[1][i]=2*(mypow(v[i+1]-v[i])-1)%MOD*mypow(a[1]-v[i+1])%MOD;
	dp[1][mp[a[1]]]=2;
	for (int i=2;i<=n;i++){
		if (a[i-1]>=a[i]){
			for (int j=0;j<=mp[a[i]];j++) dp[i][j]=dp[i-1][j];
			for (int j=mp[a[i]]+1;j<=mp[a[i-1]];j++) dp[i][mp[a[i]]]+=dp[i-1][j];
			dp[i][mp[a[i]]]=dp[i][mp[a[i]]]*2%MOD;
		}else{
			for (int j=0;j<mp[a[i-1]];j++) dp[i][j]=dp[i-1][j]*mypow(a[i]-a[i-1])%MOD;
			dp[i][mp[a[i-1]]]=2*dp[i-1][mp[a[i-1]]]*(mypow(v[mp[a[i-1]]+1]-a[i-1])-1)%MOD*mypow(a[i]-v[mp[a[i-1]]+1])%MOD;
			for (int j=mp[a[i-1]]+1;j<mp[a[i]];j++) dp[i][j]=dp[i-1][mp[a[i-1]]]*2%MOD*(mypow(v[j+1]-v[j])-1)%MOD*mypow(a[i]-v[j+1])%MOD;
			dp[i][mp[a[i]]]=dp[i-1][mp[a[i-1]]]*2%MOD;
		}
	}
	for (int i=0;i<=mp[a[n]];i++) ans+=dp[n][i];
	cout<<ans%MOD;
}