#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forn(i,a,n) for(int i =a;i < n; i++)
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define pb push_back
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define MAXN 3005
int a[MAXN];
lli dp[MAXN][MAXN][2];
int used[MAXN][MAXN][2];

lli solve(int l, int r, int id){
	if( l > r ){
		return 0;
	}

	if(used[l][r][id]) return dp[l][r][id];
	used[l][r][id] = 1;
	lli ans = -1;
	if(id == 0){//maximizar
		ans = max(solve(l+1,r,!id) + a[l], solve(l,r-1,!id) + a[r]);
	}
	else{//minimizar
		ans = min(solve(l+1,r,!id) - a[l], solve(l,r-1,!id) - a[r]);
	}

	return dp[l][r][id] = ans;
}


int main(){__
	int n;
	cin >> n;
	forn(i,1,n+1) cin >> a[i];
	cout << solve(1,n,0) << endl;
}
