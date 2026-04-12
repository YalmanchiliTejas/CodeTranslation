#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second

char s[105];
int n,k;
LL dp[105][4][2];

LL f( int i, int k, int u ){
	if ( i == 0 ){
		return k == 0;
	}
	LL &ans = dp[i][k][u];
	if ( ans != -1 ) return ans;
	ans = 0;

	if ( u && s[n-i] == '0' ) ans += f(i-1,k,1);
	else ans += f(i-1,k,0);

	if ( k == 0 ) return ans;
	for ( int j = 1; j <= 9; j++ ){
		if ( u && s[n-i]-'0' < j ){
			continue;
		}
		if ( u && s[n-i]-'0' == j ){
			ans += f(i-1,k-1,1);
		} else {
			ans += f(i-1,k-1,0);
		}
	}
	return ans;
}

int main(){

	scanf("%s",&s);
	scanf("%d",&k);
	n = strlen(s);
	memset(dp,-1,sizeof(dp));

	LL ans = 0;
	for ( int i = 1; i <= n; i++ ){
		if ( i == n ){
			for ( int j = 1; j <= 9; j++ ){
				if ( s[0]-'0' == j ){
					ans += f(i-1,k-1,1);
					break;
				}
				ans += f(i-1,k-1,0);
			}
		} else {
			for ( int j = 1; j <= 9; j++ ){
				ans += f(i-1,k-1,0);
			}
		}
		// printf("%d %lld\n",i,ans);
	}
	printf("%lld\n",ans);
	return 0;
}