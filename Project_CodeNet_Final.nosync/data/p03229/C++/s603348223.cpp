#include <bits/stdc++.h>
const int INF = 1e9;
const int MODk = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
const double EPS = 1e-10;
using namespace std;
#define COUT(v) cout<<(v)<<endl
#define COUTDOUBLE(v) cout << std::setprecision(10)<<(v)<<endl;
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
#define pb(v) push_back(v)
#define V vector
#define rt return
#define rmsame(a) sort(ALL(a)),a.erase(unique(ALL(a)), a.end())
#define ENDL cout<<endl

typedef string::const_iterator State;
class PalseError {};
class Edge{
public:
    int from,to,value;
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


int main(){
    CIN(N);
    I vec;
    REP(a,N){
        CIN(b);
        vec.push_back(b);
    }
    sort(ALL(vec));
    reverse(ALL(vec));
    if(N %2 == 0){
        I guu;
        I ki;
        REP(a,N/2){
            ki.push_back(vec.at(a));
        }
        for(int a = N/2;a < N;a++){
            guu.push_back(vec.at(a));
        }
        LL insA = 0,insB = 0;
        for(int a = 0;a < guu.size();a++){
            if(a == 0){
                insA += guu.at(a);
            }else{
                insA += 2 * guu.at(a);
            }
        }
        reverse(ALL(ki));
        for(int a = 0;a < ki.size();a++){
            if(a == 0){
                insB += ki.at(a);
            }else{
                insB += 2 * ki.at(a);
            }
        }
        COUT(insB-insA);
        return 0;
    }else{
        LL ans = -1;
        I guu,ki;
        for(int a = 0;a < N/2;a++){
            guu.push_back(vec.at(a));
        }
        for(int a = N/2;a < N;a++){
            ki.push_back(vec.at(a));
        }
        LL insA = 0,insB = 0;
        for(int a = 0;a < guu.size();a++){
            insA += 2*guu.at(a);
        }
        for(int a = 0;a < ki.size();a++){
            if(a == 0 || a == 1){
                insB += ki.at(a);
            }else{
                insB += 2*ki.at(a);
            }
        }

        ans = max(ans, insA-insB);

        guu.clear();
        ki.clear();
        insA = 0;
        insB = 0;
        reverse(ALL(vec));
        for(int a = 0;a < N/2;a++){
            guu.push_back(vec.at(a));
        }
        for(int a = N/2;a < N;a++){
            ki.push_back(vec.at(a));
        }

        for(int a = 0;a < guu.size();a++){
            insA += 2*guu.at(a);
        }
        for(int a = 0;a < ki.size();a++){
            if(a == 0 || a == 1){
                insB += ki.at(a);
            }else{
                insB += 2*ki.at(a);
            }
        }

        ans = max(ans, insB-insA);
        COUT(ans);
        return 0;
    }
    rt 0;
}
