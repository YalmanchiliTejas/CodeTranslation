#include <bits/stdc++.h>
#define LOCAL
using namespace std;
template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
out << "(" << a.first << "," << a.second << ")";
return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
out << "["; bool first = true;
for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
out << "["; bool first = true;
for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
out << "{"; bool first = true;
for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
out << "{"; bool first = true;
for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
return out;
}
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cerr.write(names, comma - names) << ": " << arg1 << " |";
__f(comma + 1, args...);
}
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
//#########################################
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
int vis[100][100];
signed main(){
    int h,w;cin >> h >> w;
    vector<string> f(h);
    rep(i,h)cin >> f[i];
    int dist[h][w];
    rep(i,h)rep(j,w)dist[i][j] = -1;
    dist[0][0] = 0;
    queue<P> q;
    q.emplace(0,0);
    vis[0][0] = 1;
    while(q.size()){
        auto p = q.front();q.pop();
        int x = p.first,y = p.second;
        rep(i,4){
            int nx = p.first + dx[i],ny = p.second + dy[i];
            if(nx < 0 || ny < 0 || nx > h-1 || ny > w-1)continue;
            if(f[nx][ny] == '.')continue;
            if(vis[nx][ny])continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.emplace(nx,ny);
            vis[nx][ny] = 1;
        }

    }
    int cnt = 0;
    rep(i,h)rep(j,w)cnt += (f[i][j] == '#');
    if(dist[h-1][w-1] == h+w-2 && cnt == h+w-1)cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}