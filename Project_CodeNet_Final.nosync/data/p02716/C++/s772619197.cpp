#include <bits/stdc++.h>
using namespace std;
struct edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<int>>;
using dou =long double;
string yes="yes";
string Yes="Yes";
string YES="YES";
string no="no";
string No="No";
string NO="NO";

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(int i = m; i < (int)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum(a) accumulate(all(a),0ll)
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
#define case std::cout << "Case #" <<qqq+1<<": "
#define res resize
#define as assign
#define ffor for(;;)
#define ppri(a,b) std::cout << a<<" "<<b << std::endl
#define pppri(a,b,c) std::cout << a<<" "<<b <<" "<< c<<std::endl
#define aall(x,n) (x).begin(),(x).begin()+(n)
 
typedef long long ll;
typedef pair<int,int> P;
//typedef long long T;
const int INF = 2000000000;
const ll INF64 = 922337203685477580ll;
const ll MOD = 1000000007ll;
int main(){
    ll n;
    std::cin >> n;
    VEC(ll,a,n);
    if(n%2==0){
        std::vector<ll> s1,s2;
        s1.pb(0);
        s2.pb(0);
        rep(i,n){
            if(i%2==0)s1.pb(s1[s1.size()-1]+a[i]);
        }
        reverse(all(a));
        rep(i,n){
            if(i%2==0)s2.pb(s2[s2.size()-1]+a[i]);
        }
        ll ans=-INF64;
        rep(i,n/2+1){
            ans=max(ans,s1[i]+s2[n/2-i]);
        }
        std::cout << ans << std::endl;
    }
    else if(n==3){
        std::cout << max({a[0],a[1],a[2]}) << std::endl;
    }
    else {
        vvector(dp,ll,n+1,3,-INF64);
        dp[0][0]=0;
        dp[0][1]=0;
        dp[0][2]=0;
        dp[1][0]=a[0];
        dp[2][1]=a[1];
        dp[3][2]=a[2];
        
        rep(i,n+1){
            rep(j,3){
                if(i-2>=0){
                    dp[i][j]=max(dp[i][j],dp[i-2][j]+a[i-1]);
                    if(j!=0&&i-3>=0){
                        dp[i][j]=max(dp[i][j],dp[i-3][j-1]+a[i-1]);
                    }
                }
                
            }
        }
        std::cout << max({dp[n][2],dp[n-1][1],dp[n-2][0]}) << std::endl;
    }
    
}
