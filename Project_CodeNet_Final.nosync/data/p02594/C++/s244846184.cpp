#include<bits/stdc++.h>
using namespace std;
//#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef pair<int,int> P;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define lowbit(x) (x&-x)
const ll INF=0x3f3f3f3f;
const double EPS=1e-8;
const int N=2e5+10;
const ll mod=1e9+7;
inline ll read()
{  ll f=1,x=0;char ch=getchar();
   for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-') f=-1;
   for(;ch<='9'&&ch>='0';ch=getchar()) x=x*10+ch-'0';
   return x*f;
}
int n;
int main()
{  cin>>n;
   if(n>=30)printf("Yes\n");
   else printf("No\n"); 

}