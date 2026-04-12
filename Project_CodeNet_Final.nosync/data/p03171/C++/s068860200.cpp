#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

ll n;
vector<ll> a;
vector<vector<ll>> dp,flag;

ll f(int l,int r){
	if(flag[l][r]>0) return dp[l][r];
	flag[l][r]=1;
	if(l==r)dp[l][r]=a[l];
	else dp[l][r] = max(a[l]-f(l+1,r),a[r]-f(l,r-1));

	return dp[l][r];
}

int main()
{
	cin>>n;
	a.resize(n+1,0);
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	dp.resize(n+2,vector<ll>(n+1,0));
	flag.resize(n+2,vector<ll>(n+1,0));

	cout << f(1,n) << endl;

	return 0;
}