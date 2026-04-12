#include <bits/stdc++.h>

using namespace std;


int main(){
    int64_t n, x, m;
    cin >> n >> x >> m;
    int64_t S = 0;
    int64_t y = x;
    int cnt = 0;
    vector<bool> used(m + 1);
    int64_t s;
    while (true){
        if (used[y]){
            s = y;
            break;
        }
        used[y] = true;
        y = (y * y) % m;
    }

    y = s;
    while (true){
        S += y;
        y = (y * y) % m;
        cnt++;
        if (y == s)
            break;
    }

    int64_t ans = 0;
    y = x;
    while (true){
        ans += y;
        y = (y * y) % m;
        n--;
        if (y == s)
            break;
    }
    
    ans += n / cnt * S;
    y = s;
    for (int64_t i = n / cnt * cnt; i < n; i++){
        ans += y;
        y = (y * y) % m;
    }

    cout << ans << endl;
}