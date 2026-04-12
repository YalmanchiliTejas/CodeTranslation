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
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#include <list>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int n;
	cin>>n;
	ll a[200020];
	for(int i=0; i<n; i++) cin>>a[i];
	ll dp[4][200020];
	for(int i=0; i<4; i++) fill(dp[i], dp[i]+n+1, -1e18);
	dp[0][0]=0;
	for(int i=0; i<=3 && i<n; i++){
		dp[(i+2)/2-1][i+1]=a[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<4; j++){
			if((i+1)/2-j<0) continue;
			for(int k=i+1; k<=i+3 && k<n; k++){
				int t=(k+2)/2-((i+1)/2-j+1);
				if(t<0 || t>=4) continue;
				dp[t][k+1]=max(dp[t][k+1], dp[j][i]+a[k]);
			}
		}
	}
	ll ans=-1e18;
	for(int i=n; i>=0; i--){
		if((i+1)/2-n/2<0) break;
		ans=max(ans, dp[(i+1)/2-n/2][i]);
	}
	cout<<ans<<endl;
	return 0;
}
