#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <tuple>
#include <stack>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(),x.end()
#define print(s) cout << s << endl
typedef long long ll;
using namespace std;

int main() {
    int n,m; cin >> n >> m;
    vector<string> v(n);
    rep(i,n) cin >> v[i];
    vector<bool> row(n, false), col(m, false);
    rep(i, n)rep(k,m){
        if (v[i][k] == '#'){
            row[i] = true;
            col[k] = true;
        }
    }
    rep(i,n){
        if (!row[i]) continue;
        rep(k,m){
            if (!col[k]) continue;
            cout << v[i][k];
        }
        cout << endl;
    }
}