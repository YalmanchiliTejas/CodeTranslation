//============================================================================
// Name        : competitive_programing.cpp
// Author      : .Data_Nerd.
// Description : problem solving training
//============================================================================

#include <bits/stdc++.h>
#define Data_Nerd ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define files freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define mod 1000000007
#define OO 0x3f3f3f3f
#define NIL -1
using namespace std;
typedef long long ll;

ll memo[3005][3005];

ll n, arr[3005];

ll solve(int idx_1, int idx_2){
	if(idx_2 < idx_1)
		return 0;
	if(memo[idx_1][idx_2] != NIL)
		return memo[idx_1][idx_2];
	return memo[idx_1][idx_2] = max(arr[idx_1] - solve(idx_1 + 1, idx_2), arr[idx_2] - solve(idx_1, idx_2 - 1));
}

int main() {
	Data_Nerd
	memset(memo, NIL, sizeof(memo));

	scanf("%lld", &n);

	for(int i = 0; i < n; ++i)
		scanf("%lld", &arr[i]);

	printf("%lld", solve(0, n - 1));

	return 0;
}
