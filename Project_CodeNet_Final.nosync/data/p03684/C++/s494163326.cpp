#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
typedef pair<long long,pair<int,int>> plii;
const long long MOD = 1000000007LL;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
struct union_find{
    vector<int> par; 
    vector<int> size;
    //1からnまで初期化:par[i] = i(1<=i<=n)
    union_find(int n){
        par.push_back(0);
        for(int i = 1;i<=n;i++){
            par.push_back(i);
            size.push_back(1);
        }
    }
    int root(int a){
        if (par[a] == a) return a;
        par[a] = root(par[a]);
        return root(par[a]);
    }
    void unite(int a,int b){
        if (root(a) == root(b)) return;
        size[root(b)]+=size[root(a)];
        par[root(a)] = root(b);
    }
    bool same(int a,int b){
        return (root(a) == root(b));
    }
    //頂点aが含まれる木の大きさ(頂点数)
    int treesize(int a){
        return size[root(a)];
    }
};
int main(){
    int n;
    cin >> n;
    vector<pair<long long,int>> vecx;
    vector<pair<long long,int>> vecy;
    long long x,y;
    rep(i,n){
        cin >> x >> y;
        vecx.push_back(make_pair(x,i));
        vecy.push_back(make_pair(y,i));
    }
    sort(vecx.begin(),vecx.end());
    sort(vecy.begin(),vecy.end());
    priority_queue<plii,vector<plii>,greater<plii>> edge;
    rep(i,n-1){
        edge.push(make_pair(vecx[i+1].first-vecx[i].first,make_pair(vecx[i].second,vecx[i+1].second)));
        edge.push(make_pair(vecy[i+1].first-vecy[i].first,make_pair(vecy[i].second,vecy[i+1].second)));
    }
    union_find tree(n);
    long long ans = 0;
    while(tree.treesize(0)<n){
        plii pr = edge.top();
        if(!tree.same(pr.second.first,pr.second.second)){
            tree.unite(pr.second.first,pr.second.second);
            ans+=pr.first;
        }
        edge.pop();
    }
    cout << ans << endl;
}