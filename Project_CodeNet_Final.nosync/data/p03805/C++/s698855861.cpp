#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
#define all(v) v.begin(), v.end()
const int INF = 1 << 30;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    int res = 0;
    vector<int> route;
    rep(i,n)route.push_back(i);
    do{
        if(route.front() != 0)continue;
        int pos = 0;
        bool can = true;
        for(int i = 1;i < n;i++){
            if(find(all(graph[route[i]]),pos) != graph[route[i]].end()){
                pos = route[i];
            }else{
                can = false;
                break;
            }
        }
        if(can)res++;
    }while(next_permutation(all(route)));
    cout << res <<"\n";
    return 0;
}