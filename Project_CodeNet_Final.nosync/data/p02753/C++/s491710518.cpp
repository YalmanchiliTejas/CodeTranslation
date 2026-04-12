#include <bits/stdc++.h>
using namespace std;
#define __ <<' '<<
#define ___ <<' '
#define bash push_back
#define ALL(x) x.begin(),x.end()
//#define int long long

struct IoSetup {IoSetup() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout <<fixed<<setprecision(12);
    cerr <<fixed<<setprecision(12);
}}IoSetup;

using ll = long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int SMOD = 1000000007;
constexpr int NMOD = 998244353;
constexpr int dx[]={1,0,-1,0,1,1,-1,-1};
constexpr int dy[]={0,1,0,-1,-1,1,-1,1};

inline bool inside(int x,int y,int w,int h){return (x>=0 && y>=0 && x<w && y<h);}
template<class T>bool chmax(T &a, const T &b){return(a<b?a=b,true:false);}
template<class T>bool chmin(T &a, const T &b){return(a>b?a=b,true:false);}
inline int qp(int a,ll b,int mo){ll ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}



signed main() {

    string s;

    cin >> s;

    if(s == "AAA" or s == "BBB") cout << "No\n";
    else cout << "Yes\n";


  
    return 0;
}

