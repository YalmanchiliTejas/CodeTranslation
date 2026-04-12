#include <bits/stdc++.h>
using namespace std;
struct edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<int>>;
using dou =long double;
string Yes="Yes";
string YES="YES";
string NO="NO";
string No="No";
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(int i = m; i < (int)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define res resize
#define as assign
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
 
typedef long long ll;
//typedef long long T;
const int INF = 2000000000;
const ll INF64 = 922337203685477580ll;
//const int mod = 1000000007ll;
const ll  MOD = 1000000007LL;

int main(){
    int h,w;
    std::cin>>h>>w ;
    vvector(c,char,h,w,'0');
    reprep(i,j,h,w)std::cin >> c[i][j];
    std::vector<bool> hh(h,1),ww(w,1);
    rep(i,h){
        bool d=0;
        rep(j,w)if(c[i][j]=='#')d=1;
        if(!d)hh[i]=0;
    }
    rep(i,w){
        bool d=0;
        rep(j,h)if(c[j][i]=='#')d=1;
        if(!d)ww[i]=0;
    }
    rep(i,h){
        rep(j,w){
            if(hh[i]&&ww[j])std::cout << c[i][j];
            
        }
        if(hh[i])std::cout  << std::endl;
    }
}