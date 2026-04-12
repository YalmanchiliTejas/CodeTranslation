#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <bitset>
#include <chrono>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define DEBUG
#ifdef DEBUG
// #include "debug.h"
#else
#define debug(...) 42
#endif

const int M = 8e3+1;
const int MD=998244353;

int a[M];
ll dp[M][M],ans=0,pre[M][M];
int main() {
	fast_cin();
    int n,s;
	cin>>n>>s;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(j==0){
				dp[i][j+a[i]]=i;
			}
			else{
				dp[i][j+a[i]]=(dp[i][j+a[i]]+pre[i-1][j])%MD;
			}
		}
		for(int j=0;j<=s;j++){
			pre[i][j]=(pre[i-1][j]+dp[i][j])%MD;
		}
	}
	for(int i=1;i<=n;i++){
		ans=(ans+((n-i+1)*dp[i][s])%MD)%MD;
	}
	cout<<ans;
	return 0;
}