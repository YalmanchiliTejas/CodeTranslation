#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main() {
	vector<int>a;
	int n, k, t;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	while(true) {
		a.clear();
		scanf("%d", &n);
      if(n==0)return 0;
		f(i, n) {
			scanf("%d", &x);
			a.push_back(x);
		}
		sort(a.begin(), a.end());
      s=0;
		f(i, n-2) {
			s += a[i + 1];
		}
		ans = s / (n - 2);
		printf("%d\n", ans);
	}



	return 0;
}
