#include <iostream>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <iomanip>
#include <string.h>
#include <sstream>
#include <map>
#include <set>

#define N 100000
#define mod 1000000007
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define minn(a,b) a=min(a,b)

using namespace std;

int a[3333];
long long dp[3333][3333];

long long rec(int l, int r)
{
	if(l == r) return a[l];
	if(dp[l][r]!=-1)return dp[l][r];
	dp[l][r]=max(a[l] - rec(l + 1, r), a[r] - rec(l, r - 1));
	return dp[l][r];
}

int main(int argc, char const *argv[]) {

	int n;cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		memset(dp[i],-1,sizeof dp[i]);
	}
	cout << rec(0, n - 1);
}

