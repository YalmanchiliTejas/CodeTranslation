#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define show(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
template<typename T> using vec=std::vector<T>;

const int inf=1<<30;
const long long int infll=1LL<<62;
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
    int n;
    cin >> n;
    vector<int> h(n),w(n);
    vector<vector<int>> c(4,vector<int>(4));
    rep(i,0,n) cin >> h[i] >> w[i];
    rep(i,0,4) rep(j,0,4){
        char tmp;
        cin >> tmp;
        if(tmp=='R') c[i][j]=0;
        if(tmp=='G') c[i][j]=1;
        if(tmp=='B') c[i][j]=2;
    }

    bool flag[4][4][5][5][3];
    fill_n((bool*)flag,4*4*5*5*3,false);
    rep(y1,0,4) rep(x1,0,4) rep(y2,y1+1,5) rep(x2,x1+1,5) rep(y,y1,y2) rep(x,x1,x2) flag[y1][x1][y2][x2][c[y][x]]=true;

    auto encode=[](const bitset<16> &bs){
        int res=0;
        rep(i,0,16) if(bs[i]) res|=1<<i;
        return res;
    };

    vector<int> cost(1<<16,inf);
    queue<int> que;
    cost[0]=0;
    que.push(0);
    while(!que.empty()){
        auto state=que.front();
        que.pop();
        if(state==(1<<16)-1){
            cout << cost[state] << endl;
            return;
        }
        rep(i,0,n) rep(y,-h[i]+1,4) rep(x,-w[i]+1,4){
            int y1=max(0,y),x1=max(0,x),y2=min(4,y+h[i]),x2=min(4,x+w[i]);
            rep(j,0,3){
                if(!flag[y1][x1][y2][x2][j]) continue;
                auto next_state=state;
                rep(y_,y1,y2) rep(x_,x1,x2){
                    if(c[y_][x_]==j) next_state|=1<<(4*y_+x_);
                    else next_state&=~(1<<(4*y_+x_));
                }
                if(cost[next_state]!=inf) continue;
                cost[next_state]=cost[state]+1;
                que.push(next_state);
            }
        }
    }
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}