#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

ll dp[105][2][4];

int main(){
	string s;
	cin >> s;
	int k;
	cin >> k;
	int l = s.size();
	
	//dp初期条件
	dp[0][1][0] = 1;
	dp[0][1][1] = (s[0] - '0') - 1;
	dp[0][0][1] = 1;
	
	REP(i,l-1){
		rep(smaller, 2){
			rep(j, k+1){
				for (int x = 0; x <= 9 ; ++x) {
					int D = s[i] - '0';
					int nsmaller = smaller;  int nj = j;
					if(smaller == 0){
						if(x > D) continue;
						if(x != 0) nj++;
						if(x < D) nsmaller = 1;
						if(nj > k) continue;
					}else{
						if(x != 0) nj++;
						if(nj > k) continue;
					}
					dp[i][nsmaller][nj] += dp[i-1][smaller][j];
				}
			}
		}
	}
	
	ll ans = dp[l-1][0][k] + dp[l-1][1][k];
	cout << ans << endl;
	
    return 0;
}

