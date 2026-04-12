#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e5+5;
struct Edge
{   
    int next, to;
    Edge(int next = 0, int to = 0):next(next), to(to) {};
}edge[N<<1];
int tot, head[N];
void _add(int x, int y) { edge[++tot] = Edge(head[x], y), head[x] = tot; }
void add(int x, int y) { _add(x, y), _add(y, x); }
int n, f[N], fa[N], root, col[N];
vector<int> s[N];
void dfs(int x, int d)
{
    f[x] -= fa[x] != 0, col[x] = - 1, s[d].push_back(x);
    for(int i = head[x]; i; i = edge[i].next)
    {
        int y = edge[i].to;
        if(y == fa[x]) continue;
        fa[y] = x, dfs(y, d+1);
    } 
}
int main()
{
    n = read();
    if(n == 2) return puts("Second"), 0;
    for(int i = 1; i < n; ++i)
    {
        int x = read(), y = read();
        ++f[x], ++f[y], add(x, y);
    }
    for(int i = 1; i <= n; ++i) if(f[i] > 1) root = i;
    dfs(root, 1);
    for(int p = n; p; --p)
        for(int k = 0; k < s[p].size(); ++k)
        {
            int x = s[p][k];
            if(col[x] == -1&&col[fa[x]] == -1)
            {
                col[x] = 0, col[fa[x]] = 1, --f[fa[x]], --f[fa[fa[x]]];
                if(f[fa[x]]) return puts("First"), 0;
            }
            else if(col[x] == -1&&col[fa[x]] == 0) return puts("First"), 0;
        }
    puts("Second");
    return 0;
}