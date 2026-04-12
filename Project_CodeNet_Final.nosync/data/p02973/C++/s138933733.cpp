#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

struct UnionFind{
    vector<int> rank,p,size;
    UnionFind(int n){
        rank.resize(n,0);
        p.resize(n,0);
        size.resize(n,0);
        for(int i = 0; i < n; i++){
            p[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
    int root(int x){
        if(x != p[x]){
            p[x] = root(p[x]);
        }
        return p[x];
    }
    bool unite(int x,int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return false;
        if(rank[rx] > rank[ry]){
            p[ry] = rx;
            size[rx] += size[ry];
        }else{
            p[rx] = ry;
            size[ry] += size[rx];
            if(rank[rx] == rank[ry]){
                rank[ry]++;
            }
        }
        return true;
    }
    int tree_size(int x){
        return (size[root(x)]);
    }
};

int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i,n){
        cin>>a[i];
    }
    multiset<int> m;
    int ans = 0;
    rep(i,n){
        auto iter = m.lower_bound(a[i]);
        if(iter == m.begin()){
            ans++;
            m.insert(a[i]);
        }else{
            int d = distance(m.begin(),iter);
            iter--;
            m.erase(iter);
            m.insert(a[i]);
        }
    }
    cout << ans;
}
