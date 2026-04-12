#include "bits/stdc++.h"
using namespace std;
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define N	    100001
#define rep(i,a,b)  for(int i=a;i<b;i++)
const int n = 4 * 1e3;
long long dp[n][2];
int main() {
	int c;
	cin>>c;
	int A[c + 1];
	rep(i, 1, c + 1)
		cin>>A[i];
	for(int i = c; i >= 1; i--) {
		dp[i][0] = A[i];
		for(int j = i + 1; j <= c; j++) {
			if(A[i] + dp[j][1] >= A[j] + dp[j - 1][1]) {
				long long tem = dp[j][0];
				dp[j][0] = A[i] + dp[j][1];
				dp[j][1] = tem;
			}
			else {
				dp[j][0] = A[j] + dp[j - 1][1];
				dp[j][1] = dp[j - 1][0];
			}
		}
	}
	cout<<dp[c][0]-dp[c][1]<<endl;
}