#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include<unordered_map>
#include <cassert>
#include <string>
#include <cstring>
#include<stack>
#include<list>
#include<queue>
using namespace std;
typedef long long int ll;
# define INF 0x3f3f3f3f
long long dp[3000][3000];
long long findVal(ll* arr, int st, int en, int n)
{
	if(st>en)
	{
		return 0;
	}
	if(dp[st][en]!=0) return dp[st][en];
	int moves = n-(en-st);
	if(moves%2==1)
	{
		dp[st][en] = max(findVal(arr,st+1,en,n)+arr[st],findVal(arr,st,en-1,n)+arr[en]);
	}else
	{
		dp[st][en] = min(findVal(arr,st+1,en,n)-arr[st],findVal(arr,st,en-1,n)-arr[en]);
	}
	return dp[st][en];
}
int main()
{
	memset(dp,0,sizeof(dp[0][0]*3000*3000));
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	ll* arr = new ll[n]();
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<findVal(arr,0,n-1,n)<<endl;
}