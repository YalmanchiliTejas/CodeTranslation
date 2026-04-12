#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
ll inf=1e18+9;

/*
ac
２人を同時に探索させる（２人のx+yは同じ）．
始点・終点以外同じ場所を通らなくても最適な経路にできる．
何故１人目を探索させてから２人目を探索させるではいけないのかまだ分からない．
*/

ll h,w,a[210][210],dp[210][210][410],b=0,dx[2]={0,1},dy[2]={1,0};

ll f(ll x1,ll x2,ll sum){//最初の経路
	if(dp[x1][x2][sum]!=-1)return dp[x1][x2][sum];
	ll y1=sum-x1,y2=sum-x2,ans=0;
	rep(i,2){
		rep(j,2){
			if(x1+dx[i]>w-1 || x2+dx[j]>w-1 || y1+dy[i]>h-1 || y2+dy[j]>h-1)continue;
			//行き先が一致しないようにする
			//この方法の都合上，最初と最後だけ場合分けが必要
			if(x1+dx[i]==x2+dx[j] && y1+dy[i]==y2+dy[j])continue;
			ans=max(ans,f(x1+dx[i],x2+dx[j],sum+1));
		}
	}
	return dp[x1][x2][sum]=ans+a[sum-x1][x1]+a[sum-x2][x2];
}

int main(void){
	cin>>h>>w;
	rep(i,h)rep(j,w)cin>>a[i][j];
	rep(i,210)rep(j,210)rep(k,410)dp[i][j][k]=-1;
	cout<<f(1,0,1)+a[0][0]+a[h-1][w-1]<<endl;//最初と最後だけどうしても同じ場所にいなくちゃいけないので，個別に足す
	return 0;
}