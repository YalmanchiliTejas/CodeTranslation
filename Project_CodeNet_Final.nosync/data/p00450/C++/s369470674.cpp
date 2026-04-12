#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
	int n;
	while(cin >> n , n){
		int dp[100000] = {0};
		int pos = 0;
		rep(i,n){
			int c; cin >> c;
			if((i+1)%2 == 1){ //odd
				if(dp[pos] == 0){
					if(c)dp[pos]++; else dp[pos]--;
					continue;
				}
				if(c == 1 && dp[pos] > 0){
					dp[pos]++;
				}else if(c == 0 && dp[pos] < 0){
					dp[pos]--;
				}else{
					pos++;
					if(c == 1)dp[pos]++;
					else dp[pos]--;
				}
			}else{
				if(c == 1 && dp[pos] > 0){
					dp[pos]++;
				}else if(c == 0 && dp[pos] < 0){
					dp[pos]--;
				}else{
					if(pos == 0){
						dp[pos] *= -1;
					}else{
						dp[pos-1] -= dp[pos];
						dp[pos] = 0;
						pos--;
					}
					if(c == 1) dp[pos]++;
					else dp[pos]--;
				}
			}
		}
		int sum = 0;
		rep(i,100000){
			if(dp[i] < 0)sum += dp[i];
		}
		cout << -sum << endl;
	}
}