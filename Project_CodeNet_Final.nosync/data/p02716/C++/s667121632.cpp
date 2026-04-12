#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<map>

#define LL  long long
#define MAXN    200010
#define P   1000000007
using namespace std;
int N;
int A[MAXN];
map<int, LL> dp[MAXN];

int main()
{
    
    cin>>N;

    for(int i=1; i<=N; i++) {
        cin>>A[i];
    }    

	dp[1][0] = 0; dp[1][1] = A[1];
	dp[2][0] = 0; dp[2][1] = max(A[1], A[2]);
	for(int i=3; i<=N; i++) {
		for(int j=i/2-1; j<=(i+1)/2; j++) {
			//if(dp[i-1].count(j) && !dp[i-2].count(j-1)) continue;	// 确定每一轮都要加一个
			if(dp[i-1].count(j)) {
				dp[i][j] = dp[i-1][j];
			}
			if(dp[i-2].count(j-1)) {
				if(!dp[i].count(j))
					dp[i][j] = dp[i-2][j-1]+A[i];
				else dp[i][j] = max(dp[i][j], dp[i-2][j-1]+A[i]);
			}
		}
	}

	cout << dp[N][N/2]<<endl;
    return 0;
}