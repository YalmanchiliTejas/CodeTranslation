#include <bits/stdc++.h>
using namespace std;

char str[100050];
bool dp[100050];

int main() {
	int N;
	scanf("%d",&N);
	scanf("%s", str);
	int sl = N;
	int dx[] = {0, 1, 0, 1};
	int dy[] = {1, 1, 0, 0};
	int i=0;
	while(i<4){
		dp[0] = dx[i];
		dp[1] = dy[i];
		for (int j = 2; j < sl; j++) {
			if (str[j-1] == 'o') {
				if (dp[j-1] == 1) {
					dp[j] = dp[j-2];
				} else {
					dp[j] = 1 - dp[j-2];
				}
			} else {
				if (dp[j-1] == 1) {
					dp[j] = 1 - dp[j-2];
				} else {
					dp[j] = dp[j-2];
				}
			}
		}
		int lb = 0;
		if (dp[sl - 1] == 1) {
			if (str[sl-1] == 'o') {
				if (dp[sl - 2] == dp[0]) {
					lb++;
				}
			} else {
				if (dp[sl - 2] != dp[0]) {
					lb++;
				}
			}
		} else {
			if (str[sl - 1] == 'x') {
				if (dp[sl - 2] == dp[0]) {
					lb++;
				}
			} else {
				if (dp[sl - 2] != dp[0]) {
					lb++;
				}
			}
		}
		if (dp[0]==1){
			if(str[0]=='o'){
				if(dp[sl-1]==dp[1])lb++;
			} else {
				if(dp[sl-1]!=dp[1])lb++;
			}
		}else{
			if(str[0]=='x'){
				if(dp[sl-1]==dp[1])lb++;
			} else {
				if(dp[sl-1]!=dp[1])lb++;
			}
		}
		if (lb==2) {
			for (int j = 0; j < sl; j++) {
				if (dp[j] == 0) printf("W");
				else printf("S");
			}
			return 0;
		} else i++;
	}
	printf("-1");
}

