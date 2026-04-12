#include<bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a))
#define rep(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i <= _##i; ++i)
#define repd(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i >= _##i; --i)
#define debug(x...) printf("["#x"]="),print(x);
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fcout cout<<setprecision(4)<<fixed
using namespace std;
typedef long long ll;
//======================================
namespace FastIO{
char print_f[105];void read() {}void print() {putchar('\n');}
template <typename T, typename... T2>
inline void read(T &x, T2 &... oth){x = 0;char ch = getchar();ll f = 1;while (!isdigit(ch)){if (ch == '-')f *= -1;ch = getchar();}while (isdigit(ch)){x = x * 10 + ch - 48;ch = getchar();}x *= f;read(oth...);}
template <typename T, typename... T2>
inline void print(T x, T2... oth){ll p3=-1;if(x<0) putchar('-'),x=-x;do{print_f[++p3] = x%10 + 48;}while(x/=10);while(p3>=0) putchar(print_f[p3--]);if(sizeof...(T2)) putchar(' ');print(oth...);}} // namespace FastIO

using FastIO::print;
using FastIO::read;
//======================================
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn = 1e6+5;

ll fx(ll x,ll mod){
    x%=mod;
    return x*x%mod;
}
ll a[maxn],sum[maxn];
ll n,m;
unordered_map<int,int>mp;
ll get(int l,int r){
    if(l>r) return 0;
    return sum[r]-sum[l-1];
}
ll ans=0;
void solve(){
    ll last,net;
    for(ll i=2;;i++){
        a[i]=fx(a[i-1],m);
        sum[i]=sum[i-1]+a[i];
        if(mp.count(a[i])){
            last=mp[a[i]];
            net=i-1;
            break;
        }
        mp[a[i]]=i;
    }
    // debug(net,last)
    ll len=net-last+1;
    ans=get(1,last-1)+(n-last+1)/len*get(last,net)+get(last,(last+(n-last+1)%len-1));
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("H:\\code\\in.in", "r", stdin);
    freopen("H:\\code\\out.out", "w", stdout);
    clock_t c1 = clock();
#endif
//**************************************
    read(n,a[1],m);
    sum[1]=a[1];
    mp[a[1]]=1;
    solve();
    print(ans);
//**************************************
    
#ifndef ONLINE_JUDGE
    cerr << "Time:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
