#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define sz(a) int(a.size())
#define clr(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int inf=1e9;
const ll Inf=1e18;
const int mod=1;
template<typename T=int>
T gi() {
    T x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
template<typename T> bool chkmax(T &a,T b) { return a<b?a=b,1:0; };
template<typename T> bool chkmin(T &a,T b) { return a>b?a=b,1:0; };
int add(int a,int b) { return a+b>=mod?a+b-mod:a+b; }
int sub(int a,int b) { return a-b<0?a-b+mod:a-b; }
void inc(int &a,int b) { a=(a+b>=mod?a+b-mod:a+b); }
void dec(int &a,int b) { a=(a-b<0?a-b+mod:a-b); }
string to_string(string s) { return '"'+s+'"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b?"true":"false"); }
template<typename A,typename B> string to_string(pair<A,B> p) {
    return "("+to_string(p.fi)+","+to_string(p.se)+")";
}
template<typename T> string to_string(T v) {
    int fst=1;string ret="{";
    for(auto x:v) {
        if(!fst) ret+=",";
        fst=0,ret+=to_string(x);
    }
    ret+="}";return ret;
}
void dbg_out() { cerr<<endl; }
template<typename Head,typename... Tail> void dbg_out(Head H,Tail... T) {
    cerr<<" "<<to_string(H);
    dbg_out(T...);
}
#define dbg(...) cerr<<"{"<<#__VA_ARGS__<<"}:",dbg_out(__VA_ARGS__)

template<typename T>
int qpow(int a,T b) {
    int ret=1;
    while(b) {
        if(b&1) ret=1ll*ret*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return ret;
}

const int N=2e5+10;

int n,rmx=-inf,rmn=inf,bmx=-inf,bmn=inf;
pii a[N];
ll ans;

int main() {
    n=gi();
    for(int i=1;i<=n;i++) {
        a[i].fi=gi(),a[i].se=gi();
        if(a[i].fi>a[i].se) swap(a[i].fi,a[i].se);
        chkmax(rmx,a[i].fi);
        chkmin(rmn,a[i].fi);
        chkmax(bmx,a[i].se);
        chkmin(bmn,a[i].se);
    }
    ans=1ll*(rmx-rmn)*(bmx-bmn);
    rmx=bmx;
    sort(a+1,a+n+1);
    bmx=-inf,bmn=inf;
    for(int i=1;i<n;i++) {
        chkmax(bmx,a[i].se);
        chkmin(bmn,a[i].se);
        chkmin(ans,1ll*(max(bmx,a[n].fi)-min(bmn,a[i+1].fi))*(rmx-rmn));
    }
    printf("%lld\n",ans);
    return 0;
}
