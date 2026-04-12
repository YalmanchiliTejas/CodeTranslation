#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;

int ans = 0;
int N, M; 
void check(vector<vector<bool>> &G, vector<int> &v) {
    bool tmp = true;
    rep(i,0,N-1) {
        if (G[v[i]][v[i+1]]) {
            continue;
        }
        else {
            tmp = false;
        }
    }
    if (tmp) {
        ans++;
    }
}

int main (){
   
    cin >> N >> M;
    vector<vector<bool>> G(N,vector<bool>(N,false));

    int a,b;
    rep(i,0,M) {
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = true;
        G[b][a] = true;
    }
    vector<int> v = {};
    rep(i,0,N) {
        v.push_back(i);
    }

    do {
        if (v[0]!=0) {
            continue;
        }
        check(G,v);
    } while (std::next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}


