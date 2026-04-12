#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <utility>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <set>
#include <chrono>
#include <climits>
#include <unordered_map>
#include <iomanip> 

#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define repf(i,st,end,inc) for(int i = st; i < end; i += inc)
#define repb(i,st,end,dec) for(int i = st; i >= end; i -= dec) 

#define MOD 1000000007

#define trace1(a) cout << a << endl;
#define trace2(a,b) cout << a << " | " << b << endl;
#define trace3(a,b,c) cout << a << " | " << b << " | " << c << endl;
#define trace4(a,b,c,d) cout << a << " | " << b << " | " << c << " | "<< d << endl;

using namespace std;
using namespace std::chrono;


int main(){
	fast;
	#ifdef LOCAL_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	auto start = high_resolution_clock::now(); 

	int n;
	cin >> n;
	vector<ll int> a(n);
	vector<ll int> pref(n+1, 0);
	for(int i = 0; i< n; i++){
		cin >> a[i];
		pref[i+1] = pref[i] + a[i];
	}

	vector<vector<ll int> > dp(n, vector<ll int>(n, 0));

	for(int i = 0; i < n; i++)
		dp[i][i] = a[i];

	for(int k = 1; k < n; k++){
		for(int i = 0; i + k < n; i++){
			int j = i+k;
			ll int tot1 = pref[j+1] - pref[i+1];
			ll int tot2 = pref[j] - pref[i];
			dp[i][j] = max(a[i] + (tot1 - dp[i+1][j]), a[j] + (tot2 - dp[i][j-1]));
		}
	}

	cout << 2*dp[0][n-1] - pref[n] << "\n";

	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);	
	// cout << endl;
	// cout << fixed << setprecision(9) << double(duration.count()) / 1000000 << endl; 

	return 0;
}
