#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>

#define vi vector<int>
#define tests int t; cin>>t; while(t--)
#define ll long long
#define vll vector<long long>
#define sort(v) sort(v.begin(), v.end())
#define sortg(v) sort(v.begin(), v.end(), greater<int> ())

using namespace std;

char nums[10] = { '0','1','2','3','4','5','6','7','8','9' };
char alphsl[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
const ll MOD = 1000000007;

using namespace std;

double res(int h, int c, int a) {
	int pp = 0;
	if (a % 2 == 0) {
		pp= (h + c) * (a / 2);
		
	}
	else pp= ((h + c) * ((a - 1) / 2)) + h;
	return pp / a;
}



void solve() {

	int n;
	cin >> n;
	vll v(n);
	
	for (auto& x : v) cin >> x;

	ll currsum = 0;

	for (int i = 0; i < n; i++) 
		currsum += v[i];
	
	ll ans = 0, currdif=0;
	for (int i = 0; i < n; i++) {
		currdif += v[i];
		ans += v[i] * ((currsum - currdif)%MOD);
		ans %= MOD;
	}
	cout << ans << endl;
}

int main() {


	
	solve();

	return 0;
}