#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI 3.141592653589793238462643383279502884L
#define lli long long int
#define d double
#define mod 1000000007
#define mx 100001
using namespace std;
int main() {
	FIO;
	int n;
	cin>>n;
	vector<int> vec(n);
	lli total=0;
	for(int i=0;i<n;i++){
		cin>>vec[i];
		total+=vec[i];
	}
	vector<vector<lli>> dp(n,vector<lli>(n));//dp[l][r]->max score I can get from range l to r....
	for(int i=0;i<n;i++){
		dp[i][i]=vec[i];
		if(i!=n-1) dp[i][i+1]=max(vec[i],vec[i+1]);
	}
	for(int i=n-1;i>=0;i--){
		for(int j=i+2;j<n;j++){
			dp[i][j]=max(vec[i]+min(dp[i+2][j],dp[i+1][j-1]), vec[j]+min(dp[i+1][j-1],dp[i][j-2]));
		}
	}
	cout<<2*dp[0][n-1]-total<<endl;
}