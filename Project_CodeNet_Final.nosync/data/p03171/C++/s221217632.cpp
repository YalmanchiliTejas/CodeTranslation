//L-Deque

#include<iostream>
#include<algorithm>
#include<utility>
#include<map>
#include<string>
#include<vector>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#undef INT_MIN
#undef INT_MAX
#define LL long long
#define INT_MIN -2147483647
#define INT_MAX 1000000009
#define LL_MIN -9223372036854775807
#define LL_MAX 9223372036854775807
#define MOD 1000000007

int N, l = 0, r = N - 1;
LL a[3009];
LL dp[3009][3009], ans = 0;

int main(){
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> a[i];

	for(int i = N - 1; i >= 0; i--){
		for(int j = N - 1 - i; j >= 0; j--){
			if((i + j) % 2){
				if(i + j + 1 == N)
					dp[i][j] = -1 * a[j];
				else
					dp[i][j] = min(dp[i + 1][j] - a[N - 1 - i], dp[i][j + 1] - a[j]);
			}
			else {
				if(i + j + 1 == N)
					dp[i][j] = a[j];
				else
					dp[i][j] = max(dp[i + 1][j] + a[N - 1 - i], dp[i][j + 1] + a[j]);
			}
		}
	}
	cout << dp[0][0] << endl;
	return 0;
}


