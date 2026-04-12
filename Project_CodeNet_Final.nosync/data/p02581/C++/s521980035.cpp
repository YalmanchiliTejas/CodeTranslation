#include<cstdio>
#include<algorithm>
#include<stack>
#define st first
#define nd second

using namespace std;
struct O{
		int st;
		int nd;
		int val;
};
const int N = 2e3 + 10;

int dp[N][N],   a[3 * N], fr[N] , ba[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 3 * n; i++) {
		scanf("%d", &a[i]);
	}
	dp[a[1]][a[2]] = dp[a[2]][a[1]] = ba[a[2]] = ba[a[1]] = fr[a[2]] = fr[a[1]] =1;
	int col = 0, ma = 1;
	for(int i = 3; i < 3 *  n; i += 3){
		if(a[i] == a[i + 1] && a[i] == a[i + 2]) {
			col ++;
			continue;
		}
		sort(a + i, a + i + 3);
		stack<O> stx;
		if(a[i + 1] == a[i + 2]){
			swap(a[i], a[i + 2]);	
		}	    
		if(a[i] == a[i + 1]){
			for(int j = 1; j <= n; j++){
				if(ba[j] != 0) stx.push({a[i + 2], j, max(dp[a[i]][j] + 1, ba[j])});
				if(fr[j] != 0) stx.push({j, a[i + 2], max(dp[j][a[i]] + 1, fr[j])});
			}
			stx.push({a[i], a[i], max(dp[a[i + 2]][a[i + 2]] + 1, ma)});			
		}
		else{
			int x = max(ma, dp[a[i]][a[i]] + 1), y = max(ma, dp[a[i + 1]][a[ i +1]] + 1), z = max(ma, dp[a[i + 2]][a[i+2]] + 1);
			stx.push({a[i + 1], a[i + 2], x}), stx.push({a[i], a[i + 2], y}), stx.push({a[i], a[i + 1], z});
			stx.push({a[i + 2], a[i + 1], x}), stx.push({a[i + 2], a[i], y}), stx.push({a[i + 1], a[i], z});
			for(int j = 1; j <= n; j++){
				for(int k = 0; k < 3; k++){
					if(fr[j] !=  0) stx.push({j, a[i + k], fr[j]});
					if(ba[j] != 0)  stx.push({a[i + k], j, ba[j]});
				}
			}
		}
		while(!stx.empty()){
			int x = stx.top().st, y = stx.top().nd, z= stx.top().val;
			stx.pop();
			dp[x][y] = max(dp[x][y], z);
			fr[x] = max(fr[x], z);
			ba[y] = max(ba[y],  z);
			ma = max(ma, z);
		}	
	}
	printf("%d", col +  max(ma, dp[a[3 *n]][a[3 * n]] + 1) - 1);
}		