#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define rep_0(i, end) for(int i = 0; i < (end); ++i)
#define rep_1(i, fr, ba) for(int i = (fr); i <= (ba); ++i)
#define rep(...) overload_rep(__VA_ARGS__, rep_1, rep_0)(__VA_ARGS__)
#define overload_rep(arg_0, arg_1, arg_2, name, ...) name
#define all(vec) vec.begin(), vec.end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N;
unordered_set<int> graph[100000];

int main() {

    cin >> N;
    rep(i, N - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    unordered_set<int> que;
    rep(i, N)if(graph[i].size() == 1)que.insert(i);

    cout << ([&]{
        while(!que.empty()){
            int v = *que.begin();
            if(graph[v].size() == 0)return false;
            int u = *graph[v].begin();
            for(const int& x : graph[u]){
                graph[x].erase(u);
                if(graph[x].size() <= 1)que.insert(x);
            }
            que.erase(v);
            que.erase(u);
        }
        return true;
    }() ? "Second" : "First") << '\n';

}
