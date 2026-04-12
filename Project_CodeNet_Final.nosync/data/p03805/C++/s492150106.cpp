#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int res = 0;
    vector<int> order(n);
    rep(i, n) order[i] = i;


    do{
        if(order[0] != 0) break;
        bool flg = true;
        rep(i, n-1){
            bool found = false;
            for(int nv: g[order[i]]){
                if(nv == order[i+1]) found = true;
            }
            if(!found) flg = false;
        }

        if(flg) ++res;
    } while(next_permutation(order.begin(), order.end()));

    cout << res << endl;

    return 0;
}