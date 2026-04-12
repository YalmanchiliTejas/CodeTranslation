#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll dp[200001][3];
int visit[200001][3];
int arr[200001];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",arr+i);
	for(int i=1;i<=3;i++){
		dp[i][i-1] = arr[i];
		visit[i][i-1] = 1;
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<2+(N%2);j++){
			for(int k=0;k<2+(N%2);k++){
				int x = i-2-k;
				int y = j-k;
				if(x>0&&y>=0){
					if(visit[i][j]==0){
						visit[i][j]=1;
						dp[i][j] = dp[x][y] + arr[i];
					}
					else dp[i][j] = max(dp[i][j],dp[x][y]+arr[i]);
				}
			}
		}
	}
	ll ret = dp[N-1-(N%2)][0];
	for(int i=1;i<2+(N%2);i++) ret = max(ret,dp[N-1-(N%2)+i][i]);
	printf("%lld",ret);
	
}