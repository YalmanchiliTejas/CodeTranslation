#include <bits/stdc++.h>
using namespace std;

#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;
const double eps=1e-5;
const int N=2e5+5;
const int INF=0x3f3f3f3f;
const int dir[4][2]= {1,0,-1,0,0,1,0,-1};

struct Node
{
    int xb;
    int x;
    bool operator < (const Node& m)const
    {
        return x<m.x;
    }
} a[N];
int ans[N];
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i].x);
        a[i].xb=i;
    }
    sort(a+1,a+n+1);
    /*for(int i=1; i<=n; i++)
    {
        printf("i=%d %d %d\n",i,a[i].xb,a[i].x);
    }*/
    int mid=(n+1)/2;
    int m1=a[mid].x;
    int m2=a[mid+1].x;
    //printf("mid=%d m1=%d\n",mid,m1);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        int tmpx=a[i].x;
       // int tmpx=a[tmp].x;
        //printf("tmp=%d tmpx=%d\n",tmp,tmpx);
        //printf("%d  mid=%d\n",a[tmp].x,mid);
        if(tmpx<=m1) ans[a[i].xb]=a[mid+1].x;
        else ans[a[i].xb]=a[mid].x;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}
