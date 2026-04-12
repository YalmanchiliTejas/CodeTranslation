#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (uint64_t i = 0; i < (uint64_t)(n); i++)

int main() {
    int64_t n, x;
    cin >> n >> x;
    vector<int64_t> cnt_all = {1};
    for(int i = 1; i <= n; i++){
        cnt_all.push_back(2*cnt_all[i-1]+3);
    }
    vector<int64_t> cnt_p = {1};
    for(int i = 1; i <= n; i++){
        cnt_p.push_back(2*cnt_p[i-1]+1);
    }
    int64_t ans = 0;
    for(int i = n; i >= 0; i--){
        int64_t cai = cnt_all[i];
        int64_t cpi = cnt_p[i];
        if(x < cai-i){
            x--;
            //cout << i << " " << 0 << " " << x << " " << ans << endl;
            if(x <= 0) break;
        }
        else if(x <= cai){
            ans += cpi;
            // << i << " " << 1 << " " << x << " " << ans << endl;
            break;
        }
        else if(x <= cai+2){
            ans += cpi+1;
            //cout << i << " " << 2 << " " << x << " " << ans << endl;
            break;
        }
        else{
            ans += cpi+1;
            x -= cai+2;
            //cout << i << " " << 3 << " " << x << " " << ans << endl;
            if(x <= 0) break;
        }
    }
    cout << ans << endl;
}
