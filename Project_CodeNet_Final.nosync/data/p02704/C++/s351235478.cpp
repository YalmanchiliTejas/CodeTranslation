// #pragma GCC optimize(3,"Ofast","inline")
// #pragma GCC optimize(2)
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <cstdlib>
#include <bitset>
#include <assert.h>
#include <time.h>
#include <iomanip>
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
// char buf[(1 << 21) + 1], * p1 = buf, * p2 = buf;
// #define int long long
#define lowbit(x) (x & (-x))
#define lson root << 1, l, mid
#define rson root << 1 | 1, mid + 1, r
#define pb push_back
typedef unsigned long long ull;
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::vector<ll> VI;
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define SZ(x) ((int)((x).size()))
#define bug puts("BUG")
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
template <class T>
inline void read(T &x)
{
    int sign = 1;char c = getchar();x = 0;
    while (c > '9' || c < '0'){if (c == '-')sign = -1;c = getchar();}
    while (c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
    x *= sign;
}
#ifdef LOCAL
    FILE* _INPUT=freopen("input.txt", "r", stdin);
    // FILE* _OUTPUT=freopen("output.txt", "w", stdout);
#endif
using namespace std;
const int maxn = 510;
int s[maxn],t[maxn],br[maxn],bc[maxn],cnt[maxn],a[maxn][maxn];//s[0]:row,and;s[1]:row:or.t[0]:col,and;t[1]:col,or;
ull u[maxn],v[maxn],ans[maxn][maxn];
int main(){
	int i,j,n,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	for(i=1;i<=n;i++)scanf("%d",&t[i]);
	for(i=1;i<=n;i++)scanf("%llu",&u[i]);
	for(i=1;i<=n;i++)scanf("%llu",&v[i]);
	for(k=0;k<64;k++){//逐位判定，状压
		for(i=1;i<=n;i++)br[i]=((u[i]>>k)&1),bc[i]=((v[i]>>k)&1);//获得第k位上的值
		int hr[4]={0,0,0,0},hc[4]={0,0,0,0};//hr{(row,and,0),(row,and,1),(row,or,0),(row,or,1)}统计数量
		for(i=1;i<=n;i++)//行列计算
			hr[s[i]*2+br[i]]++,hc[2*t[i]+bc[i]]++;//hc{(col,and,0),(col,and,1),(col,or,0),(col,or,1)}
		if(hr[2]&&hc[1])return 0*printf("-1\n");//粗筛(row,or,0),(col,and,1),两者不能同时有取值
		if(hc[2]&&hr[1])return 0*printf("-1\n");//粗筛(col,or,0),(row,and,1),两者不能同时有取值
		for(i=1;i<=n;i++){//用行操作后的值，来设定初值
			cnt[i]=n;//i行上，雷同的数据有n个
			for(j=1;j<=n;j++)
				a[i][j]=br[i];//可以这样设置的理由:1&1=1,0&0=0;1|1=1,0|0=0;
		}
		for(j=1;j<=n;j++)//修改数据，符合列要求
			if(t[j]!=bc[j])//t[j]表示第j列操作数(0,and;1,or),bc[j]记录第j列操作结果的第k位置值.全1,全0情况
				for(i=1;i<=n;i++)
					if(a[i][j]!=bc[j])cnt[i]--,a[i][j]=bc[j];//列上操作，同一行雷同元素需减少。
		for(j=1;j<=n;j++){//用列操作后的值，来进行修补
			int flag=0;//判定是否找到
			if(t[j]==bc[j]){//(col,and,0,0)或者(col,or,1,1)
				for(i=1;i<=n;i++)
					if(a[i][j]==bc[j]){flag=1;break;}//找到这个为0，或为1的位置，找到一个即可。
				if(flag)continue;//若找到，继续找下一行
				for(i=1;i<=n;i++)//继续找
					if(s[i]==br[i]&&cnt[i]>=2){//s[i]表示第i行操作数(0,and;1,or),br[i]记录第i行操作结果的第k位置值,(0,and,0)至少有一个0;(1,or,1)至少有一个1.cnt[i]>=2至少有两个雷同
						cnt[i]--,a[i][j]=bc[j];//因至少有两个雷同，故可更改
						break;
					}
			}
			//存在兜了一圈，没改成功的情况，不用担心，之后，会有检查。
		}
		for(i=1;i<=n;i++)//生成待定矩阵元素
			for(j=1;j<=n;j++)
				ans[i][j]|=((ull)a[i][j]<<k);//第k位的处理
	}
	for(i=1;i<=n;i++){//行检验
		ull c=ans[i][1];
		for(j=2;j<=n;j++)
			if(s[i]==0)c=c&ans[i][j];
			else c=c|ans[i][j];
		if(c!=u[i])return 0*printf("-1\n");
	}
	for(j=1;j<=n;j++){//列检验
		ull c=ans[1][j];
		for(i=2;i<=n;i++)
			if(t[j]==0)c=c&ans[i][j];
			else c=c|ans[i][j];
		if(c!=v[j])return 0*printf("-1\n");
	}
	for(i=1;i<=n;i++){//经历了考验
		for(j=1;j<=n;j++)
			printf("%llu ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
