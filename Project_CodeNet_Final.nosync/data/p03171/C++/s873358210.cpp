#include<bits/stdc++.h>
using namespace std;

long long f(vector<long long> &v, int i, int j, vector<vector<long long> > &dp) {
	if(i == j)
      	return v[i];
  
 	if(dp[i][j] != -1)
      	return dp[i][j];
  
  	dp[i][j] = max(v[i] - f(v, i+1, j, dp),
                   v[j] - f(v, i, j-1, dp));
                   
    return dp[i][j];
}
int main() {
  	int N;
 	cin>>N;
  	vector<long long> v(N,0);
  	
  	for(int i = 0 ; i < N ; i++) {
    	cin>>v[i];
    }
  
  	vector<vector<long long> > dp(N, vector<long long> (N, -1));
  	cout << f(v, 0, N-1, dp) << endl;
  	return 0;
}