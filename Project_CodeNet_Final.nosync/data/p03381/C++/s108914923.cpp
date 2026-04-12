#include<iostream> 
#include<string> 
#include<cstring> 
#include<vector> 
#include<map> 
#include<algorithm> 
#include<queue> 
#include<set> 
#include<cstdio> 
#include<functional> 
#include<iomanip> 
#include<cmath> 
#include<stack> 
#include<iomanip>
#include<functional>
using namespace std;
const int maxn = 2*(int)(1e5)+1000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
typedef long long LL;
typedef unsigned long long ull;
int a[maxn], num[maxn];
vector<int>ans;
int main() {
	//freopen("E:\\test.txt", "r", stdin);
	int n;
	while (~scanf("%d", &n)) {
		ans.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
			a[i] = num[i];
		}
		sort(num, num + n);
		int l = num[n / 2-1], r = num[n / 2];
		for (int i = 0; i < n; i++) {
			if (a[i] <= l) ans.push_back(r);
			else ans.push_back(l);
		}
		for (int i = 0; i < ans.size(); i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}