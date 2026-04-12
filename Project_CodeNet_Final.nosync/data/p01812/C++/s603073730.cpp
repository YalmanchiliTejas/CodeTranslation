#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int n,m,k;
int d[101];
int e[101][101];
int dp[2][1<<16];
int go[101];
bool calced[1<<16];

int main(void){
	scanf("%d%d%d",&n,&m,&k);
	memset(go,-1,sizeof(go));
	for(int i=0;i<m;i++){
		scanf("%d",&d[i]);
		d[i]--;
		go[d[i]]=i;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			scanf("%d",&e[i][j]);
			e[i][j]--;
		}
	}
	int prev=0,now=1;
	memset(dp,false,sizeof(dp));
	memset(calced,false,sizeof(calced));
	dp[0][(1<<m)-1]=true;
	int cnt=0;
	while(1){
		for(int i=0;i<(1<<m);i++){
			if(dp[prev][i]){
				if(calced[i])continue;
				calced[i]=true;
				for(int j=0;j<k;j++){
					int bit=0;
					for(int l=0;l<m;l++){
						if(i>>l & 1){
							if(go[e[d[l]][j]]>=0){
								bit|=(1<<go[e[d[l]][j]]);
							}
						}
					}
					dp[now][bit]=true;
				}
			}
		}
		cnt++;
		if(dp[now][0]){
			printf("%d\n",cnt);
			return 0;
		}
		swap(now,prev);
	}
	return 0;
}