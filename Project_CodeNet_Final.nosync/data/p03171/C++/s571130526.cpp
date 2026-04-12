#include <bits/stdc++.h>
using namespace std;

int n;
long long a[3005];
long long memo[3005][3005][2];
const long long INF = 1e15;

long long solve(int lpointer, int rpointer, int turn){
	
	if(rpointer < lpointer) return 0LL;
	if(memo[lpointer][rpointer][turn] != INF) return memo[lpointer][rpointer][turn];
	
	long long& p = memo[lpointer][rpointer][turn];
	
	if(turn == 0){
		
		p = solve(lpointer + 1, rpointer, turn^1) + a[lpointer];
		p = max(p, solve(lpointer, rpointer - 1, turn^1) + a[rpointer]);
		
		return p;
	}
	
	if(turn == 1){
		
		p = solve(lpointer + 1, rpointer, turn^1) - a[lpointer];
		p = min(p, solve(lpointer, rpointer - 1, turn^1) - a[rpointer]);
		
		return p;
	}
}

int main(){
	
	for(int i = 0 ; i < 3000 ; i ++)
		for(int j = 0 ; j < 3000 ; j ++)
			memo[i][j][0] = memo[i][j][1] = INF;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	
	cout << solve(0, n - 1, 0) << "\n";
	
	return 0;
}