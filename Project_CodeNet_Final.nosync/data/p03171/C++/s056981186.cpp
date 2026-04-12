#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int N = 2e5+50;
const int M = 1e6;
const ll oo = 1e18;
const int mod = 1e9+7;

ll dp[3030][3030],a[3030];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n*n;i++)
		cin>>a[i];
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			if(i == j)
				dp[i][j] = a[i];
			else 
				dp[i][j] = max(a[i] - dp[i+1][j] , a[j] - dp[i][j-1]);
		}
	}
	cout << dp[0][n-1] << endl;
}