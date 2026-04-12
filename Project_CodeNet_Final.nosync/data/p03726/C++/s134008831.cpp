#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10010;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> Array;
typedef vector<Array> Graph;
typedef pair<double, double> pdd;
const ull mod = 1000000000 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
    int N;
    cin >> N;
    set<int> G[N];
    REP(i, N-1){
        int x, y;
        cin >> x >> y;
        x--;y--;
        G[x].insert(y);
        G[y].insert(x);
    }
    set<pii> D;
    REP(i, N){
        D.insert(make_pair(G[i].size(), i));
    }
    while(D.size()){
        if(D.begin()->first == 0){
            cout << "First" << endl;
            return 0;
        }
        int x = D.begin()->second;
        int y = *G[x].begin();
        for(set<int>::iterator itr = G[y].begin();itr!=G[y].end();itr++){
            int r = *itr;
            D.erase(make_pair(G[r].size(), r));
            G[r].erase(y);
            D.insert(make_pair(G[r].size(), r));
            }
        D.erase(make_pair(G[x].size(), x));
        D.erase(make_pair(G[y].size(), y));
    }
    cout << "Second" << endl;
    return 0;
}