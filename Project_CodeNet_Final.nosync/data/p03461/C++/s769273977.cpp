#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<set>
#include<cmath>
#include<vector>

using namespace std;

#define INF 1000000000
#define pprint(x) print(x),putchar(' ')
#define fprint(x) print(x),putchar('\n')

//#define getchar() (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1 << 15],*SS = BB,*TT = BB;
inline long long read()
{
	long long x = 0;int f = 1;
	char ch = getchar();
	for(;!isdigit(ch);ch = getchar())
		if(ch == '-')
			f = -1;
	for(;isdigit(ch);ch = getchar())
		x = x * 10 + (ch ^ 48);
	return x * f;
}
void print(long long x)
{
	if(x < 0)
		putchar('-'),x = -x;
	if(x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}
const int N = 410,K = 20;

int f[N][N],d[K][K];
struct edge
{
    int u,v,w;
}e[N * N];
int n,m;
int main()
{
    n = read(),m = read();
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            d[i][j] = read();
    for(int i = 0;i <= 100;i++)
        for(int j = 0;j <= 100;j++)
            for(int x = 1;x <= n;x++)
                for(int y = 1;y <= m;y++)
                    f[i][j] = max(f[i][j],d[x][y] - i * x - j * y);
    int res;
    for(int x = 1;x <= n;x++)
        for(int y = 1;y <= m;y++)
        {
            res = INF;
            for(int i = 0;i <= 100;i++)
                for(int j = 0;j <= 100;j++)
                    res = min(res,f[i][j] + i * x + j * y);
            if(res != d[x][y])
			{
                puts("Impossible");
                return 0;
            }
        }
    puts("Possible");
    puts("202 10401");
    for(int i = 1;i <= 100;i++)
        pprint(i),pprint(i + 1),puts("X");
    for(int i = 102;i < 202;i++)
        pprint(i),pprint(i + 1),puts("Y");
    for(int i = 0;i <= 100;i++)
        for(int j = 0;j <= 100;j++)
            pprint(i + 1),pprint(202 - j),fprint(f[i][j]);
    puts("1 202");
    return 0;
}