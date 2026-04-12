#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    while(a >= MOD)
        a -= MOD;
    while(a < 0)
        a += MOD;
}

void mult(int &a, int b) {
    a = 1LL * a * b % MOD;
};

int len(pair<int, int> a) {
    return a.second - a.first + 1;
}

int isInside(pair<int, int> a, pair<int, int> b) {
    return a.first >= b.first and a.second <= b.second;
}

int two(int n) {
    int ans = 1, temp = 2;
    for(int i = 0; (1 << i) <= n; i += 1) {
        if((1 << i) & n)
            mult(ans, temp);
        mult(temp, temp);
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> v(n, 0);

    for(int i = 0; i < n; i += 1) {
        cin >> v[i];
    }
    
    auto nxt = [&] (int i) {
        if(i + 1 < n)
            return v[i + 1];
        return 0;
    };

    auto prv = [&] (int i) {
        if(i - 1 >= 0)
            return v[i - 1];
        return 0;
    };

    vector<pair<int, int>> plateaus;
    vector<vector<int>> minim(n, vector<int> (n, numeric_limits<int>::max()));

    for(int i = 0; i < n; i += 1) {
        for(int j = i; j < n; j += 1) {
            minim[i][j] = min(minim[i][j], v[j]);
            if(j - 1 >= i)
                minim[i][j] = min(minim[i][j], minim[i][j - 1]);
            if(prv(i) < minim[i][j] and nxt(j) < minim[i][j]) {
                plateaus.push_back({i, j});
            }
        }
    }

    sort(plateaus.begin(), plateaus.end(), [&] (pair<int, int> a, pair<int, int> b) {
        return len(a) > len(b);
    });

    int p = plateaus.size();
    vector<bool> seen(p, 0);
    vector<int> dp_alt(p, 0), dp_whatever(p, 0);
    
    auto all = [&] (int index) {
        return (dp_whatever[index] + 2LL * dp_alt[index]) % MOD;
    };

    function<void(int, int)> rec = [&] (int index, int ground) {

        seen[index] = 1;
        vector<int> sons;
        int min_h = minim[plateaus[index].first][plateaus[index].second];

        for(int i = 0; i < p; i += 1) {
            if(i != index and isInside(plateaus[i], plateaus[index]) and not seen[i]) {
                rec(i, min_h);
                sons.push_back(i);
            }
        }       

        dp_alt[index] = 1;
        int rem = len(plateaus[index]);

        for(auto son : sons) {
            mult(dp_alt[index], 2 * dp_alt[son] % MOD);
            rem -= len(plateaus[son]);
        }

        dp_whatever[index] = two(rem);
        
        for(auto son : sons) {
            int coef = (4LL * dp_alt[son] + dp_whatever[son]) % MOD;
            mult(dp_whatever[index], coef);
        }

        add(dp_whatever[index], -(2 * dp_alt[index] % MOD));
        mult(dp_alt[index], two(min_h - ground - 1));
    };
    
    rec(0, 0);
    int ans = all(0);
    cout << ans << "\n";
}