#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define INF (1000000000)
#define MOD (1000000007)
using namespace std;

typedef vector<int> VI;
typedef vector<int>::iterator VII;
typedef vector<double> VD;
typedef vector<double>::iterator VDI;
typedef pair<int, int> PII;


int array[100];

int main()
{
	int n, a, b, c, x;
	while (scanf("%d %d %d %d %d", &n, &a, &b, &c, &x), n + a + b + x + x){
		for (int i = 0; i < n; i++){
			scanf("%d", &array[i]);
		}
		
		int t = -1;
//		bool stop[100] = {false};
		int cnt = 0;
		while (t < 10000 && cnt < n){
			if (array[cnt] == x){
//				stop[cnt] = true;
				cnt++;
			}
			x = (a * x + b) % c;
			t++;
		}
		
		if (cnt == n){
			printf("%d\n", t);
		}
		else {
			puts("-1");
		}
	}
	
	return 0;
}