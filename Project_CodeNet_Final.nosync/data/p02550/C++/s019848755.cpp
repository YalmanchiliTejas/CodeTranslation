#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const double PI  = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const LL INF  = 0x3f3f3f3f3f3f3f3f;
const int N=3e5+10;
const int M=1e6+10;
const int mod=1e9+7;
inline LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
inline LL lcm(LL a, LL b) { return a * b / gcd(a, b); }
inline LL read(){LL x=0,f=1;char c=getchar();while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}return x*f;}
inline LL qpow(LL x,LL k=mod-2,LL m=mod){LL res=1;while(k){if(k&1) res=res*x%m;x=x*x%m;k>>=1;}return res;}
/*=================================================================================================================*/
LL n,x,m;
map<LL,int> mp;
vector<LL> vec;

int main(){
    cin>>n>>x>>m;
    LL now=x;mp[now]=1;
    while(1){
        now=now*now%m;mp[now]++;
        if(mp[now]==2) break;
    }
    vec.push_back(now);
    while(1){
        now=now*now%m;mp[now]++;
        if(mp[now]==3) break;
        vec.push_back(now);
    }
    if(n<=mp.size()){
        LL ans=now=x;
        for(int i=2;i<=n;i++){
            now=now*now%m;
            ans+=now;
        }
        cout<<ans<<endl;
    }
    else{
        LL ans=now=x;
        for(int i=2;i<=mp.size();i++){
            now=now*now%m;
            ans+=now;
        }
        n-=mp.size();
        LL sum=0;
        for(int i=0;i<vec.size();i++) sum+=vec[i];
        ans+=sum*(n/vec.size());
        for(int i=0;i<n%vec.size();i++) ans+=vec[i];
        cout<<ans<<endl;
    }
    return 0;
}
