#include<bits/stdc++.h>
#define eps 1e-6
#define ll long long
#define IOS cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define int long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
const ll mod=1000000007;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll Max(ll a,ll b){return a>=b?a:b;}
ll Min(ll a,ll b){return a<=b?a:b;}
ll qpow(ll a,ll b){ll s=1;while(b>0){if(b%2==1){s=s*a;}a=a*a;b=b>>1;}return s;}
ll qpowmod(ll a, ll b, ll c){ll res,t;res=1;t=a%c;while(b){if(b&1){res=res*t%c;}t=t*t%c;b>>=1;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline long long read(){long long k=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}return k*f;}
inline void write(long long x){if(x<0)x=-x,putchar('-');if(x>9)write(x/10);putchar(x%10+'0');}
using namespace std;
//head file

int main()
{
        int num;
        cin>>num;
        if(num>=30)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    return 0;
}
