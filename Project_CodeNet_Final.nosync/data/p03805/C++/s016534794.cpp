#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int h,w;
vector<vector<char>> vec;
vector<pair<int,int>> s;

vector<vector<int>> bfs() {
    vector<vector<int>> d(h,vector<int>(w,INF));
    queue <pair<int,int>> q;
    
    for(auto p:s){
        int sy,sx;
        tie(sy,sx)=p;
        q.push(make_pair(sy,sx));
        d[sy][sx]=0;
    }
    
    while(!(q.empty())) {
        pair<int,int> now=q.front(); q.pop();
        
        rep(i,4) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            
            if(0<=ny && ny<h && 0<=nx && nx<w && vec[ny][nx]!='#' && d[ny][nx]==INF) {
                q.push(pair<int,int> (ny,nx));
                d[ny][nx] = d[now.first][now.second] + 1;
            }
        }
    }
    
    return d;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<bool>> edge(n,vector<bool>(n,false));
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        edge[a][b]=true;
        edge[b][a]=true;
    }
    
    vector<int> perm(n-1);
    rep(i,n-1) perm[i]=i+1;
    
    int ans=0;
    do{
        vector<int> vec;
        vec.push_back(0);
        rep(i,n-1) vec.push_back(perm[i]);
        
        bool add=true;
        rep(i,n-1){
            if(!edge[vec[i]][vec[i+1]]) add=false;
        }
        if(add) ans++;
    }while(next_permutation(all(perm)));
    cout<<ans<<endl;
}
