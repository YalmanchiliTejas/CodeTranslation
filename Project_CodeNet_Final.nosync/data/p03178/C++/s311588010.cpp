#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int man = 2e5+10;
#define IOS ios::sync_with_stdio(0)
#define ull unsigned ll
#define uint unsigned
#define pai pair<int,int>
#define pal pair<ll,ll>
#define IT iterator
#define pb push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);++i)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);--i)
#define endl '\n'
#define ll long long
ll mo = 1e9+7;
ll mod;
int dp[man][100];
char p[man];

int dfs(int pos,int pre,bool limit,int sum){
	if(!pos)return sum%mod==0;
	int &x = dp[pos][sum];
	if(!limit&&x!=-1)return x;
	int ans = 0;
	int up = limit ? p[pos]-'0' : 9;
	For(i,0,up){
		ans = (1ll*ans + dfs(pos-1,i,limit&&i==up,(sum+i)%mod))%mo;
	}
	if(!limit)x = ans;
	return ans;
}

int slove(){
	int len = strlen(p+1);
	For(i,1,len/2)swap(p[i],p[len-i+1]);
	return dfs(len,-1,1,0);
}

int main() {
	#ifndef ONLINE_JUDGE
		//freopen("in.txt", "r", stdin);
		//freopen("out.txt","w",stdout);
	#endif
	memset(dp,-1,sizeof(dp));
	scanf("%s%d",p+1,&mod);
	printf("%d\n",(slove()-1+mo)%mo);
	return 0;
}