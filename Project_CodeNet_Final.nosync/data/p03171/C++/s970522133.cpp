#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include<algorithm> 
using namespace std;
// main() is where program execution begins.
// long int X = 0;
// long int Y = 0;
long long int dp[3000][3000];

long int rslt(int i, int j, long int a[], bool flg){
		if(i > j) return 0;
		if(dp[i][j] != 0) return dp[i][j];
		if(flg) return dp[i][j] = max(a[i] + rslt(i+1, j, a, !flg), a[j] + rslt(i, j-1, a, !flg));
		else return dp[i][j] = min(-a[i] + rslt(i+1, j, a, !flg), -a[j] + rslt(i, j-1, a, !flg));
		
}


int main() {
int N;
cin >> N;
long int a[N];
for (int i = 0; i < N; ++i)
{
	cin >> a[i];
}
	cout << rslt(0, N-1, a, true);
}