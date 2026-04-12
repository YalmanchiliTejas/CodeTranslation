#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define debug(x) cout<<#x<<": "<<x<<endl

template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using P = pair<int,int>;

// ←↓→↑
int dx[4] = {-1,0,+1,0};
int dy[4] = {0,1,0,-1};
int Y,X;
vector<string> s;
vector<P> loop;
int cost[50][50];

bool space(P p){
    int y = p.first, x = p.second;
    if(!(y>=0 && x>=0 && y<Y && x<X)) return false;
    if(s[y][x] == '#') return false;
    return true;
}

P next(P p,int dir){
    return P(p.first+dy[dir], p.second+dx[dir]);
}

void dfs(P p,int dir,int depth){
    int y = p.first, x = p.second;
    if(p == P(0,0) && cost[0][0]) return;
    if(cost[y][x]){
        loop.push_back({cost[y][x],depth});
    }
    cost[y][x] = depth;
    for(int turn : {-1,0,+1,+2}){
        int nd = (dir+4+turn)%4;
        P to = next(p,nd);
        if(space(to)){
            dfs(to,nd,depth+1);
            break;
        }
    }
}

bool solve(){
    s.clear();
    s.resize(Y);
    loop.clear();
    rep(y,50)rep(x,50) cost[y][x] = 0;
    rep(y,Y) cin>>s[y];
    dfs(P(0,0),1,1);
    int corner[] = {cost[Y-1][0], cost[Y-1][X-1], cost[0][X-1]};
    if(!(cost[Y-1][0] && cost[Y-1][X-1] && cost[0][X-1])){
        return false;
    }
    bool ng = false;
    for(P lp: loop){
        rep(i,3){
            if(lp.first<=corner[i] && corner[i]<=lp.second){
                ng = true;
            }
        }
    }
    return !ng;
}

int main(void){
    while(cin>>Y>>X, Y|X){
        cout<<((solve()) ? "YES" : "NO")<<endl;
    }
    return 0;
}

