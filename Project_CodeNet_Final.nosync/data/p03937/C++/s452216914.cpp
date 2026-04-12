#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

using namespace std;



void solve(){
    int h,w;
    cin>>h>>w;
    vector<string>maze(h);
    rep(i,h)cin>>maze[i];
    int cur=0;
    rep(i,h){
        if(i){
            rep(j,cur){
                if(maze[i][j]=='#'){
                    cout<<"Impossible\n";
                    return;
                }
            }
        }
        while(cur+1<w&&maze[i][cur+1]!='.'){
            ++cur;
        }
        for(int j=cur+1;j<w;++j){
            if(maze[i][j]=='#'){
                cout<<"Impossible\n";
                return;
            }
        }
    }
    cout<<"Possible\n";
}
 
signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}