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

long long n, x, m;
long long nextX[100010];
long long ans;

int main()
{
	scanf("%lld%lld%lld", &n, &x, &m);
	
	for (int i = 0 ; i < m ; i++) {
		nextX[i] = -1;
	}
	
	
	ans = x;
	long long nLeft = n - 1;
	long long newX;
	std::vector<long long> cycle;
	while (nLeft > 0) {
		nLeft--;
		newX = (x * x) % m;
		nextX[x] = newX;

		if (nextX[newX] != -1) {
			long long px = newX;
			cycle.push_back(px);
			while (px != x) {
				px = nextX[px];
				cycle.push_back(px);
			}
			
			break;
		}
		ans = ans + newX;		
		x = newX;
	}
	
	if (nLeft >= 0) {
		if (cycle.size() != 0) {
			long long sz = cycle.size();
	//		printf("%d\n", sz);
			
			long long sect = 0;
			for (int i = 0 ; i < cycle.size() ; i++) {
	//			printf("%d ", cycle[i]);
				sect = sect + cycle[i];
			}
	//		printf("\n");
				
				
			long long count = nLeft / sz;
			long long r = nLeft % sz;
			ans = ans + sect * count;
			for (int i = 0 ; i <= r ; i++)
				ans = ans + cycle[i];
			
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}


