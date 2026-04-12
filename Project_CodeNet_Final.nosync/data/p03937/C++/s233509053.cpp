//Ruthless Coding 
#include <bits/stdc++.h>

#define uni(x)      (x).resize(unique(ALL(x)) - (x).begin())
#define fprint(v)   for(auto x : v) cout << x << ' '
#define ALL(x)      (x).begin(), (x).end()
#define MP(x, y)    make_pair(x, y)
#define SZ(x)       int((x).size())
#define PB(x)       push_back(x)
#define ll          long long
#define S           second 
#define F           first
#define nl          '\n'

using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
mt19937_64 rnd;

const int N = 2e5 + 5;
int h, w;
char m[9][9];
char g[9][9];
const int dx[] = {1, 0};
const int dy[] = {0, 1};
void print(){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << m[i][j];
        }
        cout << nl;
    }
    cout << nl;
}
void go(int x, int y){
    if(x == h - 1 && y == w - 1){
        // print();
        bool ok = true;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                ok &= (m[i][j] == g[i][j]);
            }
        }
        if(ok){
            cout << "Possible";
            exit(0);
        }
    }
    for(int i = 0; i < 2; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx >= 0 && nx < h && ny >= 0 && ny < w){
            m[nx][ny] = '#';
            go(nx, ny);
            m[nx][ny] = '.';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> g[i][j];
            m[i][j] = '.';
        }
    }
    m[0][0] = '#';
    go(0, 0);
    cout << "Impossible";
    return 0;
}
/*
    *** Most Impo.. -> check base case always
    1. Overflow Check (*, +)
    2. Index check (0 - based or 1 - based)
    3. Check for n = 1, 2, 3, 4....
    4. Corner Cases
*/