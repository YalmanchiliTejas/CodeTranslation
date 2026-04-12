#include "bits/stdc++.h"
using namespace std;
#define ll long long;
const int nax = 3005;
long long dp[nax][nax];

int main() {
    int n;
    cin >>n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
     cin >>a[i];
    }
    // dp[0][n-1]
    for(int L = n - 1; L >= 0; --L) {
        for(int R = L; R < n; ++R) {
            if(L == R) {
                dp[L][R] = a[L];
            }
            else {
                dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
            }
        }
    }
  /*  for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++) cout <<dp[i][j]<<" ";
    	cout <<endl;
	}
}*/
 cout <<dp[0][n-1]<<"\n";
}
