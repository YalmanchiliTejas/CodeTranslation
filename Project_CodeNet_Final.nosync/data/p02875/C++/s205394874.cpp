#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

const int N=1e7+1;
const int M=998244353;
int bp(int a,int pw){ 
    int r=1;
    for(;pw;(a*=a)%=M,pw/=2)if(pw&1)(r*=a)%=M;
    return r;
}
int inverse(int a){return bp(a%M,M-2);} 
int fc[N],ifc[N];
struct pcfc{pcfc(){
        fc[0]=1;
        for(int i=1;i<N;++i)fc[i]=(fc[i-1]*i)%M;
        ifc[N-1]=inverse(fc[N-1]);
        for(int i=N-2;i>=0;--i)ifc[i]=(ifc[i+1]*(i+1))%M;
}}pcfc;
int C(int n,int k){
    if(k<0||k>n)return 0;
    return(((fc[n]*ifc[k])%M)*ifc[n-k])%M;
}
int p[N];


int32_t main(){
    int n;
    cin>>n;
    p[0]=1;
    for(int i=1;i<=n;++i)p[i]=(p[i-1]*2)%M;
    int bad=0;
    for(int a=n/2+1;a<=n;++a){
        bad+=C(n,a)*p[n-a]%M;
    }
    bad%=M;
    int p3=1;
    for(int i=1;i<=n;++i)(p3*=3)%=M;
    int ans=p3-bad*2;
    ans%=M;
    ans+=M;
    ans%=M;
    cout<<ans<<'\n';
    return 0;
}
