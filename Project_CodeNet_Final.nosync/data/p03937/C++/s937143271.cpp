#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 8+5;
int n, m, vis[N][N];
char s[N][N];
void dfs(int x, int y)
{
    vis[x][y] = 1;
    if(s[x+1][y] == '#') dfs(x+1, y);
    else if(s[x][y+1] == '#') dfs(x, y+1);
}
int main()
{
    n = read(), m = read();
    for(int i = 1; i <= n; ++i) scanf("%s", s[i]+1);
    if(s[1][1] == '#') dfs(1, 1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(s[i][j] == '#'&&!vis[i][j])
                return puts("Impossible"), 0;
    puts("Possible");
    return 0;
}