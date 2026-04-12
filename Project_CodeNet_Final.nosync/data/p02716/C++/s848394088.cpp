#include<bits/stdc++.h>
using namespace std;
//#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef pair<int,int> P;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define lowbit(x) (x&-x)
const ll INF=0x3f3f3f3f;
const double EPS=1e-7;
const int N=2e5+10;
const ll mod=1e9+7;
inline ll read()
{  ll f=1,x=0;char ch=getchar();
   for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-') f=-1;
   for(;ch<='9'&&ch>='0';ch=getchar()) x=x*10+ch-'0';
   return x*f;
}
ll n,x,a[N];
map<int,ll>dp[N];
ll solve(int now,int cnt)
{  
   if((now+1)/2<cnt)return -INF*1000000;
   if(cnt==0||now<1)return 0;
   if(dp[now].count(cnt))return dp[now][cnt]; 
   return dp[now][cnt]=max(solve(now-2,cnt-1)+a[now],solve(now-1,cnt));
}
int main()
{  cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   cout<<solve(n,n/2);
}