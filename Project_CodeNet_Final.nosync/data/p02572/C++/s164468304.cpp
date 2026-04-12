#include <bits/stdc++.h>
#include <iostream>
#include <functional>
#include <vector>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define rep1(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=a;i>=n;i--)
#define per1(i,a,n) for (int i=a;i>n;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define endl "\n"
#define pi 3.14159265358979323846264338327950288419716939937510
#define IOS cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod=1000000007;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll qpow(ll a,ll b){ll s=1;while(b>0){if(b%2==1){s=s*a;}a=a*a;b=b>>1;}return s;}
ll qpowmod(ll a, ll b, ll c){ll res, t;res=1;t=a%c;while(b){if(b & 1){res=res*t%c;}t=t*t%c;b>>=1;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline long long read(){long long k=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}return k*f;}
inline void write(long long x){if(x<0)x=-x,putchar('-');if(x>9)write(x/10);putchar(x%10+'0');}
// head
const int maxn=2e5+5;
ll t,n,a[maxn],b[maxn],ans;
signed main()
{
    //IOS;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n;
    ans=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=n; i>=1; i--)
    {
        b[i]=(b[i+1]+a[i])%mod;
    }
    for(int i=1; i<=n-1; i++)
    {
        //cout<<a[i]<<' '<<b[i+1]<<endl;
        ans=(ans+(a[i]*b[i+1])%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/
