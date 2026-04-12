#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

vector<int> edge[1010];
vector<int> path;

int ans = 0;
int n,m;

void verify(vector<int> now){
    int t = now.size();
    // rep(i,t) cout<<now[i]<<" ";
    // cout<<endl;

    for(int i=0;i<t-1; i++){
        bool isok = false;
        for(auto a : edge[now[i]]){
            if(a == now[i+1]) isok = true;
        }
        if(!isok) {
            return;
        }
    }
    ans++;
    return;
}

void dfs(vector<int> now){
    if(now.size()==n){
        verify(now);
        return;
    }
    now.push_back(1);
    while(now.back() < n) {
        now.back()++;
        int t=0;
        for(auto a : now) {
            if(a==now.back()) t++;
        }
        if(t>1) continue;
        dfs(now);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,m){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    path.push_back(1);
    dfs(path);
    cout<<ans<<endl;

}