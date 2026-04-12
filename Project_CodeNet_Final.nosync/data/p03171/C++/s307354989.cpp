#include <bits/stdc++.h>
using namespace std;
#define int long long
inline long long in(){long long x=0;char c=getchar();bool neg=false;while(c!='-'&&('0'>c||c>'9')) c=getchar();if(c=='-') neg=true,c=getchar();while('0'<=c&&c<='9') x=10*x+c-'0',c=getchar();if(neg) x=-x;return x;}
inline void out(long long x){if(x<0) putchar('-'),x=-x;if(x>9) out(x/10);putchar(x%10+'0');}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(false),cin.tie(nullptr);
#define task "l"
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define mt make_tuple
#define all(a) a.begin(),a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))
#define _ putchar(' ')
#define __ putchar('\n')
const int N=3010;
int n,s;
int a[N];
int f[N][N];
int F(int l,int r)
{
    if(l>r) return 0;
    if(f[l][r]!=-1) return f[l][r];
    int ans;
    if((l+r)%2!=n%2) ans=max(F(l+1,r)+a[l],F(l,r-1)+a[r]);
    else ans=min(F(l+1,r)-a[l],F(l,r-1)-a[r]);
    return f[l][r]=ans;
}
main()
{
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    cin>>n;
    forinc(i,1,n) cin>>a[i],s+=a[i];
    reset(f,-1);
    cout<<F(1,n);
}
