#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//#include<atcoder/all>
#include<iostream>
#include<cstdint>
#include<cstddef>
#include<set>
#include<vector>
using namespace std;
//using namespace atcoder;
using i32 = int_fast32_t;
using i64 = int_fast64_t;
using usize = uint_fast64_t;
#define rep(i, n) for (usize i = 0; i < (usize)(n); i++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using P = pair<i64,i64>;
vector<vector<i64>> edges;
i64 cnt,n;
void dfs(set<i64> st, i64 now){
    if(st.count(now))return ;
    st.insert(now);
    if(st.size() == n){
        cnt++;
        return ;
    }
    for(auto v:edges[now])dfs(st,v);
}
int main(){
ios::sync_with_stdio(false);
std::cin.tie(nullptr);
i64 m;
cin >> n >> m;
edges.resize(n);
rep(i,m){
    i64 a,b;
    cin >> a >> b;
    edges[a - 1].emplace_back(b - 1);
    edges[b - 1].emplace_back(a - 1);
}
set<i64> st;
dfs(st,0);
cout << cnt << endl;
}