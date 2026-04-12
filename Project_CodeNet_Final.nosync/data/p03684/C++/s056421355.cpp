#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

// union find
class union_find {
public:
    int n;
    vector<int> parent, rnk, num;
    
    union_find(int n) : n(n), parent(n), rnk(n, 0), num(n, 1) {rep(i, n) parent[i] = i; }
    
    int root(int x){ return (parent[x] == x) ? x : root(parent[x]); }
    
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if (x == y) {
            return;
        }
        if (rnk[x] < rnk[y]) {
            parent[x] = y;
            num[y] += num[x];
        }
        else{
            parent[y] = x;
            num[x] += num[y];
            if (rnk[x] == rnk[y]) {
                rnk[x]++;
            }
        }
        n--;
    }
    
    bool same(int x, int y) {return root(x) == root(y);}
    
    int count(int x){ return num[root(x)]; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    
    int N;
    cin >> N;
    vector<pair<int, int>> A(N), B(N);
    rep(i, N){
        int x, y;
        cin >> x >> y;
        A[i] = mp(x, i);
        B[i] = mp(y, i);
    }
    sort(all(A)), sort(all(B));
    vector<pair<int, pair<int, int>>> P;
    rep(i, 1, N){
        P.pb(mp(abs(A[i].first - A[i - 1].first), mp(A[i].second, A[i - 1].second)));
        P.pb(mp(abs(B[i].first - B[i - 1].first), mp(B[i].second, B[i - 1].second)));
    }
    
    sort(all(P));
    
    union_find uf(N);
    
    ll ans = 0;
    for(auto p: P){
        if(!uf.same(p.second.first, p.second.second)){
            uf.unite(p.second.first, p.second.second);
            ans += p.first;
        }
        
        if(uf.count(0) == N) break;
    }
    
    output(ans);
    
    return 0;
}