/** @Date    : 2017-05-06 21:02:21
  * @FileName: D.cpp
  * @Platform: Windows
  * @Author  : Lweleth (SoundEarlf@gmail.com)
  * @Link    : https://github.com/Lweleth
  * @Version : $Id$
  */
#include <bits/stdc++.h>
#define LL long long
#define PII pair<int ,int>
#define MP(x, y) make_pair((x),(y))
#define fi first
#define se second
#define PB(x) push_back((x))
#define MMG(x) memset((x), -1,sizeof(x))
#define MMF(x) memset((x),0,sizeof(x))
#define MMI(x) memset((x), INF, sizeof(x))
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e5+20;
const double eps = 1e-8;

int a[N];

vector<int> vt[N];
int flag;
int dfs(int s, int pre)
{
	if(flag == 1)
		return 0;
	int cnt = 0;
	int l = vt[s].size();
	for(int i = 0; i < l; i++)
	{
		int np = vt[s][i];
		if(np == pre)
			continue;
		if(dfs(np, s))
			cnt++;
		if(cnt >= 2)
		{
			printf("First\n");
			flag = 1;
			exit(0);
		}
	}
	return cnt ^ 1;
}

int main()
{


	int n;
	cin >> n;
		for(int i = 0; i < n - 1; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			vt[x].PB(y);
			vt[y].PB(x);
		}
		flag = 0;
		int f = dfs(1, -1);
		if(f == 1)
			printf("First\n");
		else if(!flag)
			printf("Second\n");
    return 0;
}