#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll INF=1e18;
int n;
ll a[3001];
ll memo[2][3001][3001];
ll solve(int p, int l, int r){
	if(l==r){
		if(p==0) return a[l];
		else return -a[l];
	}
	if(memo[p][l][r]!=INF) return memo[p][l][r];
	if(p==0){
		ll ans=max(solve(1-p, l+1, r)+a[l], solve(1-p, l, r-1)+a[r]);
		return memo[p][l][r]=ans;
	}else{
		ll ans=min(solve(1-p, l+1, r)-a[l], solve(1-p, l, r-1)-a[r]);
		return memo[p][l][r]=ans;
	}
}
int main()
{
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			memo[0][i][j]=memo[1][i][j]=INF;
		}
	}
	cout<<solve(0, 0, n-1)<<endl;
	return 0;
}