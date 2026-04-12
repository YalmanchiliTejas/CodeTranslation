#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <list>

using namespace std;

#define fi first
#define se second
#define long long long
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ii arr[200003];
int ans[200003];

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i].fi);
		arr[i].se = i;
	}
	sort(arr+1, arr+n+1);
	for(int i = 1; i <= n; i++)
	{
		int idx = arr[i].se;
		if(i <= n/2) ans[idx] = arr[n/2+1].fi;
		else ans[idx] = arr[n/2].fi;
	}
	for(int i = 1; i <= n; i++)
	{
		printf("%d\n", ans[i]);
	}
}



