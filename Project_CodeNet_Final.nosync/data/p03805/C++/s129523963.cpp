#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int inf = 1<<30;
constexpr int mod = 1e9+7;
constexpr ll infl = 1ll<<60;
vector<int> E[10];
int n,m;
int rec(int u,int pre,int state){
    if((state | 1<<u) == ((1<<n)-1))return 1;
    int ret = 0;
    for(auto v : E[u])if(pre != v and !((state & 1<<v))){
        ret += rec(v,u,state|1<<u);
    }
    return ret;
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        a--;b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    cout << rec(0,-1,0) << endl;
    return 0;
}