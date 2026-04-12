#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

ll dp[103][2][4];

int main(){
	string n;
	cin >> n;
	int k;
	cin >> k;
	
	ll l = n.size();
	
	dp[0][0][0] = 1;
	
	rep(i,l){
		rep(smaller,2){
			rep(j,k+1){
				rep(x,10){
					int D = n[i] - '0';
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
					dp[i+1][nsmaller][nj] += dp[i][smaller][j];
				}
			}
		}
	}
	
	cout << dp[l][1][k] + dp[l][0][k] << endl;
	
    return 0;
}