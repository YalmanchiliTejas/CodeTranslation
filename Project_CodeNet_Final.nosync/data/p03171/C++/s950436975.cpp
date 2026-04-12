#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
#define N 3010
using namespace std;
ll dp[N][N], A[N];
ll fun(int a, int b){
	if(a > b)
		return 0;
	if(dp[a][b] != -1)
		return dp[a][b];
	ll maxi = -1e18;
	maxi = max(maxi, A[a] + min(fun(a + 2, b), fun(a + 1, b - 1)));
	maxi = max(maxi, A[b] + min(fun(a + 1, b - 1), fun(a, b - 2)));
	return dp[a][b] = maxi;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll sumi = 0;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		sumi += A[i];
	}
	memset(dp, -1, sizeof(dp));
	ll x = fun(0, n - 1);
	cout << x - (sumi - x) << '\n';


}