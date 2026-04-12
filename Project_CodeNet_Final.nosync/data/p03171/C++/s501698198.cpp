#include <bits/stdc++.h>
using namespace std;
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define int long long
#define fi first
#define se second

const int maxn=3010;
int a[maxn],n,f[maxn][maxn];

int calc(int l,int r)
{
    if(l>r) return 0;
    if(f[l][r]!=-1) return f[l][r];
    int ret;
    if(((r+l)%2)!=n%2) ret=max(calc(l+1,r)+a[l],calc(l,r-1)+a[r]);
    else ret=min(calc(l+1,r)-a[l],calc(l,r-1)-a[r]);
    return f[l][r]=ret;
}
main()
{
   // ios_base::sync_with_stdio(false);
    cin>>n;
    forinc(i,1,n) cin>>a[i];
    memset(f,-1,sizeof f);
    cout<<calc(1,n);

}
