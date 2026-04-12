#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define zy -2147382637
#define bql 2147483647
#define ll long long
#define ull unsigned long long
#define ld long double
#define il inline
#define sz(x) x.size()
#define maxn 100010
#define rp(i, l, r) for (int i = l; i <= r; i++)
#define rb(i, r, l) for (int i = r; i >= l; i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;
ll max(ll a,ll b){if(a>b)return a;else return b;}
ll min(ll a,ll b){if(a<b)return a;else return b;}
ll lowbit(ll x){return x&(-x);}
ll prime(ll x){
   if(x<=1)return false;
   for(int i=2;i<=int(sqrt(x));i++){
       if(x%i==0)return false;
   }return true;
}bool cmp(ll a,ll b){return a>b;}
ll gcd(ll a,ll b){ll r;while(b>0){r=a%b;a=b;b=r;}return a;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline int readint() {
    int f=1,x=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
    return f*x;
}
inline ll readll() {
    ll f=1,x=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
    return f*x;
}
void fl(string name){
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}
const int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1},
          dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
ll n;
int main(){
    cin>>n;
    if(n<30)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}
/* stuff to remember
    * int overflow, array bounds
    * special cases (n=1? n=0?)
    * do something instead of nothing and stay organized
    * USE STATIC ARRAYS
    * DEFINING ARRAYS BEFORE main()
    * DO NOT DEFINE ARRAYS IN main()
    * USE INT INSTEAD OF LL,NOTICE THE MLE
*/