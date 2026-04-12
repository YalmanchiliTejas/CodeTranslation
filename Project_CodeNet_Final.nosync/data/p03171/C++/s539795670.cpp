#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
typedef pair<int,int> pii;
typedef pair <long long,long long> pll;
typedef long long ll; 
typedef long double ld; 
const ll mod = 1e9+7;
ll dp[3001][3001][2];
ll solve(vector <ll > &v , int i, int j, bool turn)
{
	if(i > j)
		return 0;
	if(dp[i][j][turn] != -1)
		return dp[i][j][turn];
	if(turn == 1)
		return dp[i][j][turn] = max(v[i] + solve(v, i+1 , j, 0), v[j] + solve(v, i, j-1, 0));
	else
		return dp[i][j][turn] = min(solve(v, i+1 , j, 1), solve(v, i, j-1, 1));
	
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    ll n,sum = 0 ; cin >> n;
    vector <ll> v(n+1);
    memset(dp, -1, sizeof(dp));
    for(ll i = 1; i<=n ; i++)
    {	cin >> v[i];
		sum+=v[i];
	}
	ll x = solve(v, 1, n, true);
	cout<< 2*x -sum;
	return 0;
}
 
