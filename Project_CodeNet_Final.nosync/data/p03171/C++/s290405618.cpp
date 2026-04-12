#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef queue<int> qi;
typedef queue<ll> ql;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define INF 200000009
ll dp[3005][3005];// dp(x,y) = when sequence [x,y] remains, the number of x-y
int n;
ll a[3005];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=n;++i)// have taken n-1 numbers, 1 number left
		if (n&1) dp[i][i]=a[i];
		else dp[i][i]=-a[i];
	for (int l=1;l<n;++l){// have taken n-l-1 numbers, l+1 numbers left
		bool flag=(n-l-1)&1;// flag=0: Taro's turn; flag=1: Jiro's turn
		for (int x=1;x+l<=n;++x){
			if (flag==0) dp[x][x+l]=max(dp[x][x+l-1]+a[x+l],dp[x+1][x+l]+a[x]);
			else dp[x][x+l]=min(dp[x][x+l-1]-a[x+l],dp[x+1][x+l]-a[x]);
		}
	}
	cout<<dp[1][n]<<endl;
	return 0; 
}