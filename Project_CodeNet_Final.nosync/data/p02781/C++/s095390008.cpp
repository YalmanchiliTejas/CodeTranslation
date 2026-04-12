#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;


int FACT(int n, int k) {
    int ret = 1;
    for (int i = 0; i < k; ++i) {
        ret = ret * (n - i);
    }
    return ret;
}

int POW(int n, int k) {
    int ret = 1;
    for (int i = 0; i < k; ++i) {
        ret = ret * n;
    }
    return ret;
}


int COM(int n, int k) {
    if (n==0 || n <= k ) return 1;
    int x = FACT(n, k);
    int y = FACT(k, k);
    return x / y; 
}

int main() {
    string s; 
    int k;
    cin >> s;
    cin >> k;
    int n = s.size();
    int ret = 0;
    rep(i, s.size()) {
        int is = s[i] - '0';
        n--;
        if (is == 0) continue;
        if (n >= k) ret += COM(n, k) * POW(9, k);
        if (n >= k -1) ret += COM(n, k-1) * (is-1) * POW(9, k-1);
        k--;
        if (k==0) {
            ret++; 
            break;
        }
    }
    cout << ret << endl;

    return 0;
}