#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include<bitset>
#include <utility>
#include <assert.h>
using namespace std;
#define rank rankk
#define mp make_pair
#define pb push_back
#define xo(a,b) ((b)&1?(a):0)
//#define LL ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,int> pli;
const int INF=0x3f3f3f3f;
const ll INFF=0x3f3f3f3f3f3f3f3fll;
const int MAX=2e4+5;
const int MAX_N=MAX;
const ll MOD=998244353;
const long double pi=acos(-1.0);
//const double eps=0.00000001;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<class T> inline
void read(T& num) {
    bool start=false,neg=false;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=true;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
inline ll powMM(ll a,ll b,ll M){
    ll ret=1;
    a%=M;
//    b%=M;
    while (b){
        if (b&1) ret=ret*a%M;
        b>>=1;
        a=a*a%M;
    }
    return ret;
}
void open()
{
    freopen("1009.in","r",stdin);
    freopen("out.txt","w",stdout);
}
const int N = 1 << 19;//能不能改并不确定
const ll P = 998244353;//貌似可以随用随改？（998244353 时G取3是可以的）
const int G = 3;//原根
const int NUM = 20;

ll  wn[NUM];
ll  A[N], B[N],C[N];

ll quick_mod(ll a, ll b, ll m)
{
    ll ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % m;
            b--;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

void GetWn()//预处理原根的幂次
{
    for(int i = 0; i < NUM; i++)
    {
        int t = 1 << i;
        wn[i] = quick_mod(G, (P - 1) / t, P);
    }
}

void Rader(ll a[], int len)
{
    int j = len >> 1;
    for(int i = 1; i < len - 1; i++)
    {
        if(i < j) swap(a[i], a[j]);
        int k = len >> 1;
        while(j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k) j += k;
    }
}
void NTT(ll a[], int len, int on=1)//NTT的数组 下标从0开始 数组长度len
{
    Rader(a, len);
    int id = 0;
    for(int h = 2; h <= len; h <<= 1)
    {
        id++;
        for(int j = 0; j < len; j += h)
        {
            ll w = 1;
            for(int k = j; k < j + h / 2; k++)
            {
                ll u = a[k] % P;
                ll t = w * a[k + h / 2] % P;
                a[k] = (u + t) % P;
                a[k + h / 2] = (u - t + P) % P;
                w = w * wn[id] % P;
            }
        }
    }
    if(on == -1)
    {
        for(int i = 1; i < len / 2; i++)
            swap(a[i], a[len - i]);
        ll inv = quick_mod(len, P - 2, P);
        for(int i = 0; i < len; i++)
            a[i] = a[i] * inv % P;
    }
}
void Conv(ll a[], ll b[], int n)//多项式乘法 NTT 与其还原
{
    NTT(a, n, 1);
    NTT(b, n, 1);
    for(int i = 0; i < n; i++)
        a[i] = a[i] * b[i] % P;
    NTT(a, n, -1);

}

char a[MAX],b[MAX];
int e,m;
ll inv[MAX],fac[MAX<<2];
int main()
{
    GetWn();
    scanf("%s",a);scanf("%s",b);
    int le=strlen(a);
    for(int i=0;i<le;i++){
        if(a[i]=='1'||b[i]=='1'){
            if(a[i]==b[i])++m;
            else ++e;
        }
    }
    e>>=1;
//    cout<<m<<" "<<e<<endl;

    fac[0]=1;for(int i=1;i<=20001;i++)fac[i]=(ll)i*fac[i-1]%MOD;
    inv[10001]=powMM(fac[10001],MOD-2,MOD);
    for(int i=10001;i>=1;i--)inv[i-1]=(ll)i*inv[i]%MOD;
//    printf("m=%d e=%d\n",m,e);
    for(int i=0;i<=m;i++)
        C[i]=inv[i+1];
    A[0]=1;
    ll f=e;
    int len=1;
    while((1<<len)<=(m<<1))++len;
    for(ll t=e;t;t>>=1)
    {
        if(t&1LL)
        {
            memset(B,0,sizeof(B));
            for(int i=0;i<=m;i++)B[i]=C[i];
            Conv(A,B,1<<len);
            for(int i=m+1;i<(1<<len);i++)A[i]=0;
        }
//        printf("!~~~~\n");
//        Conv(B,B,m+1);
//        NTT(C, m+1, 1);
//        for(int i = 0; i <=m; i++)
//            C[i] = C[i] * C[i] % P;
//        NTT(C, m+1, -1);
        NTT(C, 1<<len, 1);
        for(int i = 0; i <(1<<len); i++)
            C[i] = C[i] * C[i] % P;
        NTT(C, 1<<len, -1);
        for(int i=m+1;i<(1<<len);i++)C[i]=0;
//        e>>=1;
    }
    ll an=0;
    ll tem=fac[m]*fac[f]%MOD*fac[f+m]%MOD;
    for(int i=0;i<=m;i++)
        an=(an+A[i])%MOD;
    printf("%lld\n",an*tem%MOD);

}
