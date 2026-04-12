#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

static const int INTINF = (2147483647);
static const ll LLINF = (9223372036854775807);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;

namespace Printer{
    void print(vector<int> v){
        rep(i, v.size()){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    void print(vector<vector<int> > vv){
        rep(i, vv.size()){
            rep(j, vv[i].size()){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void print(pair<int, int> p){
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
};

//--global--//



//----------//

int solve(int n, int m, vector<vector<int> > vv, int dep, vector<int> used, int v){
    used[v] = 1;
    if(dep == n-1){
        rep(i, n){
            if(used[i] == 0) return 0;
        }
        return 1;
    }
    int ans = 0;
    rep(i, vv[v].size()){
        int u = vv[v][i];
        if(used[u] == 0)
            ans += solve(n, m, vv, dep+1, used, u);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//

    int n, m;
    cin >> n >> m;
    vector<vector<int> > vv(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        vv[a].push_back(b);
        vv[b].push_back(a);
    }

    vector<int> used(n);
    cout << solve(n, m, vv, 0, used, 0) << endl;
    
    return 0;
}
