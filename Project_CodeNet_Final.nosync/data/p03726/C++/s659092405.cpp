//It's like the first time I realized that
//All You Need Is Love


#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.2")

#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()

inline void opting() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int inp() {
    int x;
    cin >> x;
    return x;
}

void make_unique(vector<int> &vec, bool sorted = false) {
    if(!sorted)
        sort(all(vec));
    vec.resize(unique(all(vec)) - vec.begin());
}
const int SQRT = 450, lg = 18 + 2, inlim = 2147483647;
const int maxn = 1e5 + 69, CL = 40, delta = 1e9 + 9, inf = 1e9 + 420;

bool match[maxn];
vector<int> adj[maxn];

bool win = false;
void dfs(int v, int p){

    for(auto u : adj[v])
        if(u != p)
            dfs(u, v);
    if(!match[v] and (match[p] or v == p))
        win = true;
    if(!match[v])
        match[p] = match[v] = true;
}

void add_edge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int n;
void input(){
    cin >> n;
    for(int i = 1; i < n; i++)
        add_edge(inp() - 1, inp() - 1);
}

int main(){
    opting();

    input();
    dfs(0, 0);
    if(win)
        cout << "First";
    else
        cout <<"Second ";
}
