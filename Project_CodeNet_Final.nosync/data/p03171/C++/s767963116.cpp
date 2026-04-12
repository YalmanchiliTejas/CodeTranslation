// Author: droftware
#include <bits/stdc++.h>

#define forn(i,a,n) for(int i=a;i<(int)n;i++)
#define DRT()  int t; cin>>t; while(t--)

#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif
using namespace std;

const int N = 3e3+5;

int nums[N];
long long dp[N][N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	forn(i,0,n){
		cin>>nums[i];
	}
	for(int i = n-1; i >= 0; --i){
		for(int j = i; j < n; ++j){
			if(i == j){
				dp[i][j] = nums[i];
			} else {
				dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
}
	
	

