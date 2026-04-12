#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[3005];
llint memo[3005][3005][2];

llint calc(llint l, llint r, llint t)
{
	if(l > r) return 0;
	if(memo[l][r][t] != -1) return memo[l][r][t];
	
	if(t == 1){
		return memo[l][r][t] = max(calc(l+1, r, 0)+a[l], calc(l, r-1, 0)+a[r]);
	}
	else{
		return memo[l][r][t] = min(calc(l+1, r, 1)-a[l], calc(l, r-1, 1)-a[r]);
	}
}


int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			memo[i][j][0] = memo[i][j][1] = -1;
		}
	}
	
	cout << calc(1, n, 1) << endl;
	return 0;
}