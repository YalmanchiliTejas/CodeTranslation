
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
#include <cstring>
#include <climits>
#include <iomanip>
using namespace std;

#define FORN(i, j, k) for(int i=j;i<k;i++)
#define FORR(i, j, k) for(int i=j;i>=k;i--)
#define REP(i, n) FORN(i, 0, n)
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

const int MODO = 1e+9 + 7;
const int MAX = 1e+5 + 5;
const int nax = 3e+3 + 5;

int n;
int a[MAX];
int dp[nax][nax];

int solRec(int l, int r){
	if(l==r){
		return dp[l][r] = a[l];
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	return dp[l][r] = max(a[l] - solRec(l+1,r), a[r] - solRec(l,r-1));
}

void solve(){
	REP(i,n){
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solRec(0,n-1) << endl;
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	solve();
	return 0;
}
