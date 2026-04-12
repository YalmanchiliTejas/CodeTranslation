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
    int n,m,graph[8][8]={};
    cin >> n >> m;
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;
        --b;
        graph[a][b]=graph[b][a]=1;
    }

    i64 memo[8][1<<8];
    fill_n((i64*)memo,8*(1<<8),-1);
    function<i64(int,int)> rec=[&](int u,int s){
        i64 &res=memo[u][s];
        if(res!=-1) return res;
        if(s==((1<<n)-1)) return res=1;
        res=0;
        rep(v,0,n){
            if(!graph[u][v] or (s>>v)&1) continue;
            res+=rec(v,s|(1<<v));
        }
        return res;
    };
    cout << rec(0,1) << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}
