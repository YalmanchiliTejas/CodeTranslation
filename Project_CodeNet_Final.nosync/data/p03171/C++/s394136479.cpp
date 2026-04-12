#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long ll;

int n;
ll a[3005];
ll memo[3005][3005];

ll dp(int i, int j){
	if(j < i)	return 0;
	if(i == j)	return a[i];
	if(i + 1 == j)	return max(a[i] - a[j], a[j] - a[i]);
	if(memo[i][j] != -1)	return memo[i][j];
	return memo[i][j] =  max(min(a[j] - a[i] + dp(i+1, j-1), a[j] - a[j-1] + dp(i, j-2)), min(a[i] - a[j] + dp(i+1, j-1), a[i] - a[i+1] + dp(i+2, j)));	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(memo, -1, sizeof(memo));

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << dp(0, n-1);
	
	return 0;
}