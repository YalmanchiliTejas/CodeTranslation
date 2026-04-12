/*Template by hemnath_d(Enlightened by chamow)*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vec vector<ll>
#define pll pair<ll,ll>
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define fx first
#define sx second
#define inf 100000000000000
#define minf -100000000000000
#define maxi 100005
int n;
vector<int> arr;
long long dp[200005][3][2][2];
long long solve(int pos, int state, bool flag, bool even) {
	if(pos >= n) {
		if(even == false && flag == false) {
			return minf;
		}
		return 0;
	}
	if(dp[pos][state][flag][even] != -1) {
		return dp[pos][state][flag][even];
	}
	long long ans = solve(pos + 2, state, flag, even) + arr[pos];
	if(state > 0 && (pos + 1) < n) {
		ans = max(ans, solve(pos + 3, state - 1, 1, even) + arr[pos + 1]);
	}
	if(state > 1 && (pos + 2) < n) {
		ans = max(ans, solve(pos + 4, 0, 1, even) + arr[pos + 2]);
	}
	dp[pos][state][flag][even] = ans;
	return ans;
}
int main()
{
    fastread;
    memset(dp, -1, sizeof(dp));
    cin>>n;
    arr.resize(n);
    for(int i = 0; i < n; i++) {
    	cin>>arr[i];
    }
    if(n % 2) {
    	cout<<solve(0, 2, 0, 0)<<endl;
    }
    else {
    	cout<<solve(0, 1, 0, 1)<<endl;
    }
    return 0;
}