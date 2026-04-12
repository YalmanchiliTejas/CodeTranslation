#include <bits/stdc++.h>
using namespace std;

using i64=int64_t;

#define rep(i,x,y) for(i64 i=i64(x),i##_max_for_repmacro=i64(y); i<i##_max_for_repmacro; ++i)
#define debug(x) #x << "=" << (x)
 
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif
 
const int inf=1.01e9;
const i64 inf64=4.01e18;
const double eps=1e-9;
 
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

void solve(){
    i64 N,X;
    cin >> N >> X;

    vector<i64> x(53),p(53);
    x[0]=1;
    p[0]=1;
    rep(i,1,53){
        x[i]=2*x[i-1]+3;
        p[i]=2*p[i-1]+1;
    }

    function<i64(i64,i64)> rec=[&](i64 l,i64 i){
        if(l==0) return (i64)1;
        if(i==1) return (i64)0;
        if(i==(x[l]+1)/2) return p[l-1]+1;
        if(i==x[l]) return p[l];
        if(i<(x[l]+1)/2) return rec(l-1,i-1);
        return p[l-1]+1+rec(l-1,i-(x[l]+1)/2);
    };

    cout << rec(N,X) << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
