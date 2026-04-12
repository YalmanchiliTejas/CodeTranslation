/**
 *  author: andychen
 *  created: 09.19.2020 23:46:44
**/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, x, m;
    cin >> n >> x >> m;
    
    vector<long long> cycle, used(m, -1);
    long long ans = 0, cycle_start = -1, cycle_end = -1;
    function<void (long long)> find_cycle = [&](long long newx){
        n -= 1;
        ans += newx;

        if (n == 0)
            return ;

        if (used[newx] != -1){
            cycle_start = used[newx];
            cycle_end = (int) cycle.size();
            return ;
        }
        
        used[newx] = (int) cycle.size();
        
        int rem = (newx * newx) % m;
        cycle.push_back(rem);
        find_cycle(rem);
    };

    find_cycle(x);

    long long cycle_len = cycle_end - cycle_start;
    if (cycle_len > 0){
        for (int i = cycle_start, rem = n % cycle_len; i < cycle_end; i++, rem--){
            if (rem > 0)
                ans += cycle[i];
            ans += cycle[i] * (n / cycle_len);
        }
    }

    cout << ans << '\n';

    return 0;
}
