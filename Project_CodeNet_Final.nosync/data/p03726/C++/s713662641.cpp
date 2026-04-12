#include<cstdio>
    #include<cstring>
    #include<cmath>
    #include<cstdlib>
    #include<cctype>
    #include<iostream>
    #include<string>
    #include<algorithm>
    #include<vector>
    #include<map>
    #include<stack>
    #include<queue>
    #include<set>
    using namespace std;
    typedef pair<int, int> pii;
    typedef double lf;
    typedef long long ll;
    const int inf=0x3f3f3f3f, mod=1000000007;
    struct node{int to, nxt;}edge[200200];
    int head[100100], cnt=0;
    
    inline int read()
    {
        int x=0,f=1; char ch=getchar();
        for (; ch<'0' || ch>'9'; ch=getchar()) if (ch=='-') f=-1;
        for (; ch>='0' && ch<='9'; ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
        return x*f;
    }
    
    void add(int u, int v)
    {
        edge[++cnt]=(node){v, head[u]};
        head[u]=cnt;
    }
    
    int dfs(int u, int fa)
    {
        int res=0;
        for (int i=head[u]; i; i=edge[i].nxt)
        {
            int v=edge[i].to;
            if (v!=fa) res+=dfs(v, u);
        }
        if (res>=2) return res; else return res^1;
    } 
    
    int main()
    {
        int n=read();
        for (int i=1; i<n; i++)
        {
            int u=read(), v=read();
            add(u, v); add(v, u);
        }
        if (dfs(1, 0)) printf("First\n");
            else printf("Second\n");
        return 0;
    }
