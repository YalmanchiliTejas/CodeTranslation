#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
using namespace std;
#define loop(i,n) for(int i = 0; i < (n); i++)
#define loops(i,f,n) for(int i = (f); i < (n); i++)
#define VEC vector<int>
typedef pair<int, int>pii;
typedef pair<int, bool>pib;
// vector<VEC> v (n, VEC(n))
//loop(i,n)loop(j,n)dp[i][j]=-1;
//printf("%d\n", n);

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int a, b, c;
	cin >> a >> b >> c;
	int ans;
	ans = (a - c) / (b + c);
	cout << ans << endl;
	return 0;
}