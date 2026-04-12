#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string k;
ll d,mod=1e9+7,dp[10005][105][2][2];
ll gao(int x,int y,int z,int t){
    if(x==k.size())return (y==0 and z==1);
    ll &ans=dp[x][y][z][t],b=t?k[x]-'0':9;
    if(ans!=-1)return ans;
    ans=0;
    for(int i=0;i<=b;i++)
        ans+=gao(x+1,(y+i)%d,z or i!=0,(t and i==b)?1:0)%mod;
    return ans%=mod;
}
int main(){
	cin >> k >> d;
	memset(dp,-1,sizeof(dp));
	cout << gao(0,0,0,1);
    return 0;
}