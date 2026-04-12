#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int lld;

const lld mod = 1e9+7;
const lld INF = 1e9;
//const lld MAXN = 1e9;

int main()
{
	int n,m,a[30]={0},b[30]={0};

	scanf("%d %d", &n,&m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &a[i],&b[i]);
	}

	vector<int> v(n-1);
	for(int i = 0; i < n-1; i++)
	{
		v[i] = i+2;
	}

	int sol = 0;

	do {

		int cnt = 0;
        for(int i = 0; i < m; i++)
        {
        	if (a[i] == 1 && b[i] == v[0])
        	{
        		cnt++;
        	}
        	for(int j = 0; j < n-1; j++)
        	{
        		if(j != n-2)
        		{
        			if ((a[i] == v[j] && b[i] == v[j+1]) || ( b[i] == v[j] && a[i] == v[j+1]))
        			{
        				cnt++;
        			}
        		}
        	}
        }

        if (cnt == n-1)
        {
        	sol++;
        }
    } while( next_permutation(v.begin(), v.end()) );

    printf("%d\n", sol);

	return 0;
}