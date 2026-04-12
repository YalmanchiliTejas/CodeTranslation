#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
using namespace std;
#define COUT(v) cout<<(v)<<endl
#define CIN(n)  int(n);cin >> (n)
#define LCIN(n) LL(n);cin >> (n)
#define SCIN(n) string(n);cin >> (n)
#define YES(n) cout<<((n)? "YES" : "NO")<<endl
#define Yes(n) cout<<((n)? "Yes" : "No")<<endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) <<endl

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(obj) (obj).begin(),(obj).end()

#define P pair<LL,LL>
#define I vector<int>
#define S set<int>
#define pb(v) push_back(v)
#define V vector
#define rt return
#define rmsame(a) sort(ALL(a)),a.erase(unique(ALL(a)), a.end())

typedef string::const_iterator State;
class PalseError {};
class Edge{
public:
    LL from,to,value;
    Edge(LL a,LL b,LL c){
        from = a;
        to = b;
        value = c;
    }
    Edge(LL a,LL b){
        from = a;
        to = b;
    }
};
int s[10000];
int f[10000];
int main(){
    CIN(H);CIN(W);
    vector<string> vec;
    for(int a = 0;a < H;a++){
        SCIN(s);
        vec.push_back(s);
    }
    REP(a,H){
        bool result = true;
        REP(b,W){
            if(vec.at(a).at(b) == '#'){
                result = false;
            }
        }
        if(result)s[a]=1;
    }
    REP(a,W){
        bool result = true;
        REP(b,H){
            if(vec.at(b).at(a) == '#'){
                result = false;
            }
        }
        if(result)f[a]=1;
    }

    for(int a = 0;a < W;a++){
        //cout<<f[a]<<endl;
    }
    for(int a = 0;a < H;a++){
        for(int b = 0;b < W;b++){
            if(s[a] ==0 && f[b] == 0){
                cout<<vec.at(a).at(b);
            }
        }
        cout<<endl;
    }
}

