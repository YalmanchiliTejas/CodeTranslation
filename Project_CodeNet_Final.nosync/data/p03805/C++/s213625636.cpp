#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> elements(m, vector<int>(2));
    rep(i, m) cin >> elements[i][0] >> elements[i][1];
    vector<int> order(n);
    rep(i, n) order[i] = i + 1;
    int ans = 0;
    do{
        if (order[0] != 1) break;
        bool allok = true;
        rep(i, n - 1){
            vector<int> ab(2);
            ab[0] = order[i]; ab[1] = order[i+1];
            sort(ab.begin(), ab.end());
            bool ok = false;
            for (vector<int> element : elements){
                if (ab == element) ok = true;
            }
            if (!ok){
                allok = false;
                break;
            }
        }
        if (allok) ans++;
    }while (next_permutation(order.begin(), order.end()));
    cout << ans << endl;
}
