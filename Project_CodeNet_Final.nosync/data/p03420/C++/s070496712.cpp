#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
typedef vector<long long> vlint;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<vector<long long>> vlint2;



int main() {
    lint n, k; cin >> n >> k;
    lint ans = 0;

    // a = y (mod b) の個数
    int ans_mod_b;
    int n_mod_b;
    For(b, k+1, n+1){
        n_mod_b = n%b;
        ans_mod_b = n/b;
        ans += ans_mod_b * (b - k);
        //端数
        ans += max((lint)0, n_mod_b - k + 1);
    }
    if (k == 0){
        ans = n * n;
    }
    cout << ans << endl;

    


}

