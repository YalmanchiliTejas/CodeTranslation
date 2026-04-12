#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=3030;
const ll inf=1e18;
int a[N];
ll dp[N][N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			dp[i][j]=(i+j==n)?0:((i+j)%2?inf:-inf);
	for(int i=n;i>=0;--i)
		for(int j=0;j<=n&&i-j>=0;++j){
			if(i%2){ // maximize
				if(j)dp[i-j][j-1]=max(dp[i-j][j-1],dp[i-j][j]+a[n-j]);
				if(i-j)dp[i-j-1][j]=max(dp[i-j-1][j],dp[i-j][j]+a[i-j-1]);
			}else{
				if(j)dp[i-j][j-1]=min(dp[i-j][j-1],dp[i-j][j]-a[n-j]);
				if(i-j)dp[i-j-1][j]=min(dp[i-j-1][j],dp[i-j][j]-a[i-j-1]);
			}
		}
//	for(int i=0;i<=n;++i,cout<<endl)
//		for(int j=0;j<=n;++j)
//			cout<<dp[i][j]<<" ";
	cout<<dp[0][0]<<endl;
}
