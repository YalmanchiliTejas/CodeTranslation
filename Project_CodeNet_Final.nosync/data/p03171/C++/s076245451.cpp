#include <bits/stdc++.h>

#define TR 3000
#define ll long long

using namespace std;

pair<ll, ll> dp[TR][TR][2];
bool visited[TR][TR][2];
ll a[TR];
int n;


pair<ll, ll> f(int l, int r, bool person) {
	if(visited[l][r][person])
		return dp[l][r][person];
	if(l == r) {
		if(person == 0)
			dp[l][r][0] = make_pair(a[l], 0);
		else
			dp[l][r][1] = make_pair(0, a[l]);
		visited[l][r][person] = 1;
		return dp[l][r][person];
	}
	pair<ll, ll> p_r, p_l;
	p_r = f(l, r - 1, !person);
	p_l = f(l + 1, r, !person);
	if(!person) {
		if((p_r.first + a[r] - p_r.second) > (p_l.first + a[l] - p_l.second))
			dp[l][r][person] = make_pair(p_r.first + a[r], p_r.second);
		else
			dp[l][r][person] = make_pair(p_l.first + a[l], p_l.second);
	}
	else {
		if((p_r.first - (p_r.second + a[r])) < (p_l.first - (p_l.second + a[l])))
			dp[l][r][person] = make_pair(p_r.first, p_r.second + a[r]);
		else
			dp[l][r][person] = make_pair(p_l.first , p_l.second + a[l]);
	}
	visited[l][r][person] = 1;
	return dp[l][r][person];

}

int main() {
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	pair<ll, ll> ans = f(0, n -1, 0);
	
	cout << ans.first - ans.second << endl;
	return 0;
}