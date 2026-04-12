#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

using i64=int64_t;

void solve(){
    i64 N;
    cin >> N;
    vector<i64> a(N);
    rep(i,0,N) cin >> a[i];

    i64 ans=0;
    for(;;){
        vector<i64> times(N);
        i64 sum=0;
        rep(i,0,N){
            if(a[i]<N) continue;
            times[i]=a[i]/N;
            sum+=times[i];
        }
        if(sum==0) break;
        ans+=sum;
        rep(i,0,N) a[i]=a[i]-N*times[i]+sum-times[i];
    }
    cout << ans << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
