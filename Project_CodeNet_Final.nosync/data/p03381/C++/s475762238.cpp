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
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
	vector<int>a;
	vector<int>b;
	int n;
	int x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		a.push_back(x);
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++){
		x = a[(n / 2) - 1];
		y = a[(n / 2)];
	}
	for (int i = 0; i < n; i++){
		if (b[i] <= x)	printf("%d\n", y);
		else	printf("%d\n", x);
	}



	return 0;
}