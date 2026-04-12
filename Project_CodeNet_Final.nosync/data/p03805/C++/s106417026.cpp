#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1, (i)>=0; (i)--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
ll const MOD = 1e9+7;
ll const INF = 1e18;
using namespace std;

//Graph in adjcency list
class Graph{
public:
    int N;
    vector<vector<pair<int,ll>>> adjlist;

    Graph(int n) : N(n), adjlist(n){}

    void setEdge(int a, int b, ll c){
        adjlist[a].push_back(make_pair(b, c));
    }

    int dfs(int v, vector<bool> check){
        int c = 0;
        check[v] = true;
        bool flag = true;
        for(auto i : check){
            flag &= i;
        }
        if(flag){
            return 1;
        }
        for(auto i : adjlist[v]){
            if(!check[i.first]){
                c += dfs(i.first, check);
            }
        }
        return c;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    Graph G(n);
    REP(i, m){
        int a, b;
        cin >> a >> b;
        G.setEdge(a-1, b-1, 1);
        G.setEdge(b-1, a-1, 1);
    }
    vector<bool> check(n, false);
    cout << G.dfs(0, check) << endl;

    return 0;
}