#include<bits/stdc++.h>
constexpr long long INFL = 1LL << 60;
constexpr int INF = 1 << 30;

using namespace std;

using ll = long long;
using P = tuple<int, int>;
using iarr = valarray<int>;

bool memo[10];
int nodenum,edge;

int dfs(int cnt, int node, const vector<P>& v){
    static int ret = 0;
    if(memo[node] != 0) return ret;
    if(cnt == nodenum) return ret += 1;
    memo[node] = true;
    for(int i = 0; i < edge; ++i){
        if(node == get<0>(v[i])) dfs(cnt+1, get<1>(v[i]), v);
        if(node == get<1>(v[i])) dfs(cnt+1, get<0>(v[i]), v);
    }
    memo[node] = false;
    return ret;
}

int main()
{
    cin >> nodenum >> edge;
    vector<P> v(edge);
    for(int i = 0; i < edge; ++i) cin >> get<0>(v[i]) >> get<1>(v[i]);

    cout << dfs(1, 1, v) << endl;

    return 0;
}