#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=505;
int s[N],t[N];
bool visr[N],visc[N];
ull a[N][N],u[N],v[N],b[N],c[N];
int n;
int main()
{
    ull one=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    for(int i=1;i<=n;i++) scanf("%llu",&u[i]);
    for(int i=1;i<=n;i++) scanf("%llu",&v[i]);
    for(ull k=0;k<64;k++)
    {
        memset(visr,false,sizeof(visr));
        memset(visc,false,sizeof(visc));
        vector<int>r,c;
        for(int i=1;i<=n;i++)
        {
            if(s[i]==0) r.push_back(i);
            if(t[i]==0) c.push_back(i);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
            if(s[i]==0&&(u[i]>>k&1)||t[j]==0&&(v[j]>>k&1)||s[i]==1&&(u[i]>>k&1)&&t[j]==1&&(v[j]>>k&1)&&!(visr[i]&&visc[j]))
                a[i][j]|=one<<k,visr[i]=visc[j]=true;
        }
        bool f1=false,f2=false;
        int p1=0,p2=0;
        for(int i=1;i<=n;i++)
            if((u[i]>>k&1)&&s[i]==1&&!visr[i])
        {
            f1=true;
            a[i][c[p2]]|=one<<k;
            p2++;if(p2==c.size()) p2=0;
        }
        for(int i=1;i<=n;i++)
            if((v[i]>>k&1)&&t[i]==1&&!visc[i])
        {
            f2=true;
            a[r[p1]][i]|=one<<k;
            p1++;if(p1==r.size()) p1=0;
        }
        assert(!(f1&&f2));
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        if(s[i]) b[i]|=a[i][j];
        else b[i]&=a[i][j];
        if(t[j]) c[j]|=a[i][j];
        else c[j]&=a[i][j];
        if(j==1) b[i]=a[i][j];
        if(i==1) c[j]=a[i][j];
    }
    for(int i=1;i<=n;i++)
        if(u[i]!=b[i]||v[i]!=c[i])
    {
        printf("-1\n");return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        printf(j==n?"%llu\n":"%llu ",a[i][j]);
}
