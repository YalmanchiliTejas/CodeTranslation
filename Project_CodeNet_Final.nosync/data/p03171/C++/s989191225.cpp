#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#define ll long long int
#define ld long double
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define mod(n) (n) % 1000000007
#define sp << " "
#define precision(n) cout << fixed << setprecision(n);
#define startTime time_t start, end;time(&start);
#define endTime time(&end);double tt = double(end-start);cout<<"Time taken : "<<fixed<<tt<<setprecision(5);cout <<" sec"<< endl;
 
using namespace std;
 
int main() { 
    IOS;
    ll  n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }

    ll dp[n][n];
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		dp[i][j] = LLONG_MIN;
    		if (i == j) dp[i][j] = a[i];
    	}
    }

    for (int i = n - 1; i >= 0; i--) {
    	for (int j = i + 1; j < n; j++) {
    		if (i < n - 1) dp[i][j] = max(dp[i][j], a[i] - dp[i + 1][j]);
    		if (j > 0) dp[i][j] = max(dp[i][j], a[j] - dp[i][j - 1]);
    	}
    }
    cout << dp[0][n - 1] << endl;
}