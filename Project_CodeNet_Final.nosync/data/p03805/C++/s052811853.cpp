#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct route{
    int pos; //現在地
    vector<bool> seen; //訪問済みフラグ
    set<int> passed;  //通過済みのノード

    route(int n, vector<bool> b, set<int> st){
        pos = n; 
        seen = b;
        passed = st;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> G[n];
    rep(i, m){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<route> que;
    vector<bool> vc(n); set<int> st;
    fill(all(vc), false);
    vc[0] = true; st.insert(0); //始点を訪問済みにする
    route r(0, vc, st);
    que.push(r);

    int cnt = 0;
    while(!que.empty()){
        route r = que.front(); que.pop();
        int p = r.pos;
        
        bool next = false; //移動可能な地点の有無を調べる
        rep(i, G[p].size()){
            int to = G[p][i];
            if(r.seen[to]) continue; //既に訪問済みならスルー
            route nr(to, r.seen, r.passed);
            //訪問済みフラグを立てる
            nr.seen[to] = true; nr.passed.insert(to);
            que.push(nr);
            next = true;
        }
        //移動可能な地点がもうない場合、全ての地点を通ってきたか調べる
        if(!next){
            if(r.passed.size() == n) cnt++;
        }
    }

    cout << cnt << ln;
}
    