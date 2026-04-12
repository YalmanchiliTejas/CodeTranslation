#include <bits/stdc++.h>
using namespace std;

using i64=int64_t;

#define rep(i,x,y) for(int i=(x),i##_max_for_repmacro=(y); i<i##_max_for_repmacro; ++i)
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
    int A,B;
    cin >> A >> B;
    vector<vector<int>> d(A,vector<int>(B));
    rep(i,0,A) rep(j,0,B) cin >> d[i][j];

    int N=202,M=101*101+200,S=0,T=N-1;
    static int f[101][101]={};
    rep(i,0,101) rep(j,0,101){
        int ma=0;
        rep(x,0,A) rep(y,0,B) ma=max(ma,d[x][y]-(x+1)*i-(y+1)*(100-j));
        f[i][j]=ma;
    }

    auto min_dist=[&](int x,int y){
        int dist[202];
        fill_n((int*)dist,202,inf);
        dist[0]=0;
        rep(i,0,202){
            rep(j,0,101) rep(k,0,101) dist[k+101]=min(dist[k+101],dist[j]+f[j][k]);
            rep(j,0,100) dist[j+1]=min(dist[j+1],dist[j]+x);
            rep(j,0,100) dist[j+1+101]=min(dist[j+1+101],dist[j+101]+y);
        }
        return dist[201];
    };

    rep(x,1,A+1) rep(y,1,B+1) if(min_dist(x,y)!=d[x-1][y-1]){
        cout << "Impossible" << endl;
        return;
    }

    cout << "Possible" << endl;
    cout << N << " " << M << endl;
    rep(i,0,100) cout << i+1 << " " << i+2 << " X" << endl;
    rep(i,0,100) cout << i+1+101 << " " << i+2+101 << " Y" << endl;
    rep(i,0,101) rep(j,0,101) cout << i+1 << " " << j+102 << " " << f[i][j] << endl;
    cout << S+1 << " " << T+1 << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
