#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <set>
#include <deque> 
#include <string>


using namespace std;

std::map<int, int> afterNumSet;

int n;
int a[200010];
int nextNum[200010];

int main()
{
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i++)
	{
		scanf("%d", &(a[i]));
		nextNum[i] = -1;
	}
	
	afterNumSet.clear();
	for (int i = n - 1 ; i >= 0 ; i--)
	{
		std::map<int, int>::iterator lowerBound = afterNumSet.lower_bound(a[i]);
		if ((lowerBound == afterNumSet.end()) || (lowerBound->second == 0))
		{
			nextNum[i] = -1;
			afterNumSet[a[i]]++;
			continue;
		}
		
		if (lowerBound->first == a[i])
		{
			lowerBound++;
			if ((lowerBound == afterNumSet.end()) || (lowerBound->second == 0))
			{
				nextNum[i] = -1;
				afterNumSet[a[i]]++;
				continue;
			}
		}
		nextNum[i] = lowerBound->first;
		afterNumSet[a[i]]++;
		lowerBound->second--;
		if (lowerBound->second == 0)
			afterNumSet.erase(lowerBound);
	}
	
	int count = 0;
	for (int i = 0 ; i <= n ; i++)
	{
		if (nextNum[i] == -1)
			count++;
	}
	
	printf("%d\n", count);


	return 0;
}
	