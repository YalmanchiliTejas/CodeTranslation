#include <bits/stdc++.h>
//make_tuple emplace_back next_permutation push_back make_pair second first setprecision


#if MYDEBUG
#include "lib/cp_debug.hpp"
#else
#define DBG(...) ;
#endif

using LL = long long;
constexpr LL LINF=334ll<<53;
constexpr int INF=15<<26;
constexpr LL  MOD=1E9+7;

namespace Problem{
using namespace std;
class Writer{
static ostringstream oss;
public:template<class T> void appendln(const vector<vector<T>> &ans,string spl=" ", string el="\n"){for(int i=0; i<(int)ans.size(); ++i){for(int j=0; j<(int)ans[i].size(); ++j){oss << ans[i][j];oss << (j==(int)ans[i].size()-1?el:spl);}}}
    template<class T> void appendln(const vector<T>& ans, string spl=" "){for(int i=0; i<(int)ans.size(); ++i){oss << ans[i] << (i==(int)ans.size()-1?"\n":spl);}}
    template<class T> void appendln(const T& answer){oss << answer << "\n";}
    template<class T> void append(const T& answer){oss << answer;}
    void appends(const string spl){oss.seekp((int)oss.tellp()-1);oss<<"\n";}
    template<class F, class... R>void appends(const string spl,const F& fi, const R&... rest){oss << fi << spl; appends(spl, rest...);}
    static void write(){cout << oss.str();}
    Writer(){static bool is_single =true;assert(is_single);is_single=false;};
};ostringstream Writer::oss;


class Solver{
public:
    LL n,k;

    void solve(){
        cin >> n >> k;
        LL ans = 0;
        for(int i=k+1; i<=n; ++i){
            ans+= n/i*(i-k);
            ans+= max(0ll,n%i-k+1);
        }
        if(k==0)ans-=n;
        cout<< ans <<"\n";
    }
};
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    Problem::Solver sol;
    sol.solve();
    Problem::Writer::write();
    return 0;
}

