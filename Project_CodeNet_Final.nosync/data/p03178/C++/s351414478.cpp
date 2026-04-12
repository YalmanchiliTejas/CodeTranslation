#include <bits/stdc++.h>
using namespace std;
inline long long in(){long long x=0;char c=getchar();bool neg=false;while(c!='-'&&('0'>c||c>'9')) c=getchar();if(c=='-') neg=true,c=getchar();while('0'<=c&&c<='9') x=10*x+c-'0',c=getchar();if(neg) x=-x;return x;}
inline void out(long long x){if(x<0) putchar('-'),x=-x;if(x>9) out(x/10);putchar(x%10+'0');}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(false),cin.tie(nullptr);
#define task "S"
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
const int M=1e9+7;
string s;
int d;
int b[10010];
int f[10010][110][2];
int F(int i,int r,int o)
{
    if(i>s.size()) return r==0;
    if(f[i][r][o]>-1) return f[i][r][o];
    int ans=0;
    forinc(j,0,(o ? 9 : b[i])) ans=(ans + F(i+1,(r+j)%d,j < b[i] || o))%M;
    return f[i][r][o]=ans;
}
main()
{
    fasty;
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    cin>>s;
    forinc(i,0,s.size()-1) b[i+1]=s[i]-'0';
    cin>>d;
    reset(f,-1);
    cout<<(F(1,0,0)-1+M)%M;
}
