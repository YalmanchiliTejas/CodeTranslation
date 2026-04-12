#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout);
#define pb push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define sf(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d %d",&x,&y)
#define sf3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sl2(x,y) scanf("%lld %lld",&x,&y)
#define sl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sd(x) scanf("%lf",&x);
#define pii pair<int,int>
#define pLL pair<long long,long long>
#define ff first
#define sn second
#define PRINT_CASE  printf("Case %d: ",tc++)
#define PRINT_CASENL  printf("Case %d:\n",tc++)
#define mx 100005
#define lnd tree[ind<<1]
#define rnd tree[(ind<<1)+1]
#define cnd tree[ind]
#define lndp b,(b+e)>>1,(ind<<1)
#define rndp ((b+e)>>1)+1,e,(ind<<1)+1
#define IN(a,x,y) (a>=x && a<=y)
typedef long long ll;
typedef long long int lln;
ll INF=1<<28;
//typedef long long lld;
const double pi=acos(-1.0);
int fx[]={1,-1,0,0}; //direction array
int fy[]={0,0,1,-1};
int dir[4][2]={1,0,-1,0,0,-1,0,1};
const long double EPS=1e-7;
//#define INF 10000
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}

bool cmp(int a, int b)
{
    return a<b;
}

struct compare
{
  bool operator()(const int& l, const int& r)
  {
      return l>r;
  }
};
ll inf=1e18;
int mod=1e9+7;
vector<int>G[200000];
int dp[100005][105][2];
int vis[200000];
int n,d;
vector<int>num;
void numm(string s)
{
    num.clear();
    int len=s.length();
    for(int i=0;i<len;i++){
        num.pb(s[i]-'0');
    }
    n=len;
}
int fun(int pos,int rem,int f)
{
    if(pos==n)
    {
        return rem==0;
    }
    if(dp[pos][rem][f]!=-1)
        return dp[pos][rem][f];
    int ans=0;
    if(!f)
    {
        for(int i=0;i<num[pos];i++)
        {
            ans+=fun(pos+1,(rem+i)%d,1);
            ans%=mod;
        }
        ans+=fun(pos+1,(rem+num[pos])%d,0);
        ans%=mod;
    }
    else
    {
        for(int i=0;i<10;i++)
        {
             ans+=fun(pos+1,(rem+i)%d,1);
             ans%=mod;
        }
    }
    return dp[pos][rem][f]=ans;
}

int main()
{
//    READ;
    string s;
    cin>>s;
    sf(d);
    numm(s);
    mem(dp,-1);
    cout<<(fun(0,0,0)-1+mod)%mod<<endl;
    return 0;
}
