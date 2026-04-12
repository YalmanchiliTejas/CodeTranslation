#include <bits/stdc++.h>

using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define double long double
#define endl '\n'

const int mod = (int) 1e9 + 7;
int n , D;
vector<int> a;
int cache[10001][101][2];

int solve(int i , int d , int small) {
    if(i >= n) {
        return d == 0;
    }
    if(cache[i][d][small] != -1) {
        return cache[i][d][small];
    }
    int res = 0;
    for(int dig = 0; dig <= (small ? 9 : a[i]); dig++) {
        res += solve(i + 1 , (d + dig) % D , small | (dig < a[i]));
        if(res >= mod) {
            res -= mod;
        }
    }
    return cache[i][d][small] = res;
}

signed main() {
    fio;
    string s; cin >> s >> D;
    n = (int) s.length();
    a.resize(n);
    for(int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    
    memset(cache , -1 , sizeof(cache));
    int answer = solve(0 , 0 , 0) - 1;
    if(answer < 0) {
        answer += mod;
    }
    cout << answer << endl;

    return 0;
}


