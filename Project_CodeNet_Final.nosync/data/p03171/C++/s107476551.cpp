#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define mp make_pair
#define pb push_back
#define lowbit(a) (a&(-a))
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define mst(a,v) memset(a,v,sizeof(a))
#define debug(x) cout<<#x": "<<x<<'\n';
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const int N=5000010;
const int mod=1e9+7;
const ld PI=acos(-1.0);
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

template<class T> inline void gmax(T &A,T B)
{
    (A<B)&&(A=B);
}
template<class T> inline void gmin(T &A,T B)
{
    (A>B)&&(A=B);
}

template<class T> inline bool re(T &ret)
{
    char c;
    int sgn;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}

int n;
int a[3333];
ll dp[3333][3333];

int main()
{
#ifdef local
    //freopen("in.txt", "r", stdin);
#endif
    IOS;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i],dp[i][i]=a[i];
    for(int k=2; k<=n; k++)
        for(int i=1; i+k-1<=n; i++)
        dp[i][i+k-1]=max(a[i]-dp[i+1][i+k-1],a[i+k-1]-dp[i][i+k-2]);
    cout<<dp[1][n];
    return 0;
}
