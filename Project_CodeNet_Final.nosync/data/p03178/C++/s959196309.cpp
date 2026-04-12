#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll p=1000000007;
const int maxn=2e4+5;
int d,a[maxn];
ll dp[maxn][200];

ll dfs(int pos,int sum,int limit){
	if(pos==-1) return sum%d==0;
    if(!limit && dp[pos][sum]!=-1) return dp[pos][sum]%p;
    int up=limit ? a[pos] : 9;
    ll ans=0;
    for(int i=0;i<=up;i++){
        ans+=dfs(pos-1,(sum+i)%d,limit && i==a[pos]);
        ans%=p;
    }
    if(!limit) dp[pos][sum]=ans;
    return ans;
}

ll solve(string x){
	memset(dp,-1,sizeof(dp));
	int pos=0;
	for (int i=x.size()-1;i>=0;i--){
		a[pos++]=x[i]-'0';
	}
	return dfs(pos-1,0,1);
}

int main(){
	string k;
	cin>>k>>d;
	cout<<(solve(k)+p-1)%p;
}