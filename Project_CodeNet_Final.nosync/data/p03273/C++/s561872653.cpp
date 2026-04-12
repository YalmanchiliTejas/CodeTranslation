
#include<bits/stdc++.h>
#define pii             pair<int , int >
#define in(a)           scanf("%d", &a)
#define in2(a, b)       scanf("%d%d", &a, &b)
#define in3(a, b, c)    scanf("%d%d%d", &a, &b, &c)
#define piil            pair<ll , ll >
#define inl(a)          scanf("%lld", &a)
#define inl2(a, b)      scanf("%lld%lld", &a, &b)
#define inl3(a, b, c)   scanf("%lld%lld%lld", &a, &b, &c)
#define ins(s)          scanf("%s",s)
#define prst(s)         printf("%s\n",s)
#define pn              printf("\n")
#define pr(a)           printf("%d\n", a)
#define prl(a)          printf("%lld\n", a)
#define prs(a)          printf("%d ", a)
#define pr2(a, b)       printf("%d %d\n", a, b)
#define pr3(a, b, c)    printf("%d %d %d\n", a, b, c)
#define prsl(a)         printf("%lld ", a)
#define prl2(a, b)      printf("%lld %lld\n", a, b)
#define prl3(a, b, c)   printf("%lld %lld %lld\n", a, b, c)
#define pcs(a)          printf("Case %d: ", a)
#define pf              printf
#define sc              scanf
#define m_p             make_pair
#define vi              vector<int >
#define vil             vector<ll >
#define pb              push_back
#define mem(a, b)       memset((a), (b), sizeof(a))
#define lg2(n)         (31-__builtin_clz(n))
#define PI		acos(-1.0)
#define N 200
#define debug(a)	cout<<"debug "<<a<<endl;
#define inf 2e18
#define ll long long
#define ull unsigned long long
#define MIN INT_MIN
#define MAX INT_MAX
#define __  std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);
#define Check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))
ll gcd(ll a, ll b){if(b==0) {return a;}return gcd(b, a % b);}
using namespace std;
ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
ll histogram(ll arr[],ll n) {  stack<int>s;  int area=0,i=0;  while(i<n) { if(s.empty() || arr[s.top()]<=arr[i]) s.push(i++); else { int tp=s.top(); s.pop(); int xx=arr[tp]*(s.empty() ? i : i - s.top() - 1);area=max(area,xx);}}while(!s.empty()){ int tp=s.top(); s.pop(); int xx=arr[tp]*(s.empty() ? i : i - s.top() - 1); area=max(area,xx); } return area;}
//___________________________________________________________________________________________________________________
ll dp[N][N],arr[N];
char str[N];
string v[N];
int main()
{
   ll n,m,a,b;
   ll sum=0;
   string s;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        int flg=0;
        for(int j=0;j<m;j++)
        {
            if(v[i][j]!='.') flg=1;
        }
        if(!flg)
        {
            for(int j=0;j<m;j++)
        {
            if(v[i][j]=='.') {
                dp[i][j]=1;
            }
        }
        }
    }
    for(int i=0;i<m;i++)
    {
        int flg=0;
        for(int j=0;j<n;j++)
        {
            if(v[j][i]!='.') flg=1;
        }
        if(!flg)
        {
            for(int j=0;j<n;j++)
        {
            if(v[j][i]=='.') {
                dp[j][i]=1;
            }
        }
        }
    }
    string ans[N];
    int k=0;
    for(int i=0;i<n;i++)
    {
     ans[k]="";
     int flg=0;
     for(int j=0;j<m;j++)
     {
         if(!dp[i][j])
         {
             ans[k]+=v[i][j];
             flg=1;
         }

     }
     if(flg) k++;
    }
    //cout<<k<<" "<<ans[0].size()<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

