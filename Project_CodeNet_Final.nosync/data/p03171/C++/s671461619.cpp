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

typedef long long ll;
ll dp[3005][3005][2];
void print(int i, int j) {	
	cout<<"DEG : "<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
}
int main() {
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &i : v)
		cin>>i;
	for(int j = 0; j < n; j++) {
		for(int i = j; i >= 0; i--) {
			if(i == j) {
				dp[i][j][0] = v[i];
				dp[i][j][1] = 0;
			}
			else { 
				ll first = v[i] + dp[i + 1][j][1];
				ll second = v[j] + dp[i][j - 1][1];
				if(first > second) {
						dp[i][j][0] = first;
						dp[i][j][1] = dp[i + 1][j][0];
				}
				else if(first == second) {
						dp[i][j][0] = first;
						dp[i][j][1] = min(dp[i + 1][j][0], dp[i][j - 1][0]);
				}
				else {
					dp[i][j][0] = second;
					dp[i][j][1] = dp[i][j  - 1][0];
				}
			}
		}
	}
	cout<<dp[0][n - 1][0] - dp[0][n - 1][1]<<endl;
	return 0;
}
