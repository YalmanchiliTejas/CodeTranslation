#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
//template<typename T> using vec=std::vector<T>;

const int inf=1<<30;
const long long int infll=1LL<<58;
const double eps=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

void solve(){
    int r,c,m;
    cin >> r >> c >> m;
    vector<vector<char>> grid(r,vector<char>(c));
    vector<vector<int>> time(r,vector<int>(c)),on(r,vector<int>(c)),off(r,vector<int>(c));
    vector<pii> tasks(m);
    rep(i,0,r) rep(j,0,c) cin >> grid[i][j];
    rep(i,0,r) rep(j,0,c) cin >> time[i][j];
    rep(i,0,r) rep(j,0,c) cin >> on[i][j];
    rep(i,0,r) rep(j,0,c) cin >> off[i][j];
    for(auto& t:tasks) cin >> t.first >> t.second;

    vector<vector<vector<int>>> arrival(r,vector<vector<int>>(c));
    function<bool(const pii,const pii,const pii,const int)> dfs=[&](const pii prev,const pii curr,const pii end,const int d){
        if(curr==end){
            arrival[curr.first][curr.second].emplace_back(d);
            return true;
        }
        bool pass=false;
        rep(i,0,4){
            pii next(curr.first+dx[i],curr.second+dy[i]);
            if(next.first<0 or r<=next.first or next.second<0 or c<=next.second or next==prev or grid[next.first][next.second]=='#') continue;
            pass|=dfs(curr,next,end,d+1);
        }
        if(pass) arrival[curr.first][curr.second].emplace_back(d);
        return pass;
    };

    int elapsed=0;
    rep(i,0,m-1){
        dfs(tasks[i],tasks[i],tasks[i+1],elapsed);
        elapsed+=arrival[tasks[i+1].first][tasks[i+1].second].back()-elapsed;
    }

    int ans=0;
    rep(i,0,r) rep(j,0,c){
        if(arrival[i][j].empty()) continue;
        int cost=on[i][j]+off[i][j];
        rep(k,0,arrival[i][j].size()-1){
            int tmp1=off[i][j]+on[i][j];
            int tmp2=time[i][j]*(arrival[i][j][k+1]-arrival[i][j][k]);
            cost+=min(tmp1,tmp2);
        }
        dump(cost);
        ans+=cost;
    }

    cout << ans << endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}