#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int n,m,coin[10];

bool check(int k){
	static int dp[100001];
	rep(j,m+1) dp[j]=INF; // j 円を作れない
	dp[0]=0;
	rep(i,n){
		rep(j,m-coin[i]+1) if(dp[j]<k) dp[j+coin[i]]=min(dp[j+coin[i]],dp[j]+1);
		if(dp[m]<INF) return true;
		rep(j,m+1) if(dp[j]<INF) dp[j]=0;
	}
	return false;
}

int main(){
	for(;scanf("%d%d",&n,&m),n;){
		rep(i,n) scanf("%d",coin+i);

		int lo=0,hi=m;
		while(lo<hi){
			int mi=(lo+hi)/2;
			if(check(mi)) hi=mi; else lo=mi+1;
		}
		printf("%d\n",lo);
	}

	return 0;
}