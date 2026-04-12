#include<stdio.h>
#include<map>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<utility>
#include<string.h>
#include<string>
#define n 200000
#define loop(i, a, b) for(int i=a; i<=b; i++)
using namespace std;
typedef pair<int, int> P;
typedef long long lli;
typedef double llf;
bool visit[n + 50];
lli arr[n + 50], arr2[n + 50], a, b, c, d, e, f;
string str1, str2;
struct edge{
	int from, to, weight;
	bool operator < (const edge& thing) const
	{
		return thing.weight < weight;
	}
};
vector<edge> V[n + 50];
void addedge(int a, int b, int c)
{
	edge temp;
	temp.from = a;
	temp.to = b;
	temp.weight = c;
}

////////////////////////////////////////

lli max(lli a, lli b)
{
	if(a > b) return a;
	else      return b;
}
void solve()
{
	cin >> a >> b >> c >> d >> e;
	lli ans = (a * d) + (b * e);
	for(int i=1; i <= max(d, e); i++)
	{
		lli temp = c * i * 2;
		temp += max(d - i, 0) * a;
		temp += max(e - i, 0) * b;
		ans = min(temp, ans);
//		cout << ans << '\n';
	}
	cout << ans;
}
int main()
{
	int times = 1;
//	cin >> times;
	loop(i, 0, times - 1)
	{
		solve();
		printf("\n");
	}
	return 0;
}

