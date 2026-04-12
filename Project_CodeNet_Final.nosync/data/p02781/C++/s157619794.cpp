#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int comb(int n, int k) {
    if (n < k) return 0;
    if (k == 0) return 1;
    if (k == 1) return n;
    if (k == 2) return n * (n - 1) / 2;
    if (k == 3) return n * (n - 1) * (n - 2) / 6;
}

int main() {
    string n;
    int k;
    cin >> n;
    cin >> k;
    int a = (int) n.size();
    int d0 = n[0] - '0';
    int d1 = n[1] - '0';
    int d2 = n[2] - '0';

    if(a < k){
        cout << 0 << endl;
        return 0;
    }
    int res;
    if (k == 1) {
        res = comb(a - 1, 1) * 9;
        res += d0;
    }
    if (k == 2) {
        res = comb(a - 1, 2) * 81;
        res += comb(a - 1, 1) * 9 * (d0 - 1);
        for (int i = 1; i < a; ++i) {
            if(n[i] != '0'){
                int di = n[i] - '0';
                res += comb(a - (i + 1), 1) * 9;
                res += di;
                break;
            }
        }
    }
    if (k == 3) {
        res = comb(a - 1, 3) * 729;
        res += comb(a - 1, 2) * 81 * (d0 - 1);
        int i;
        for (i = 1; i < a; ++i) {
            if(n[i] != '0'){
                int di = n[i] - '0';
                res += comb(a - (i + 1), 2) * 81;
                res += comb(a - (i + 1), 1) * 9 * (di - 1);
                break;
            }
        }
        for (int j = i + 1; j < a; ++j) {
            if(n[j] != '0'){
                int dj = n[j] - '0';
                res += comb(a - (j + 1), 1) * 9;
                res += dj;
                break;
            }
        }
    }
    cout << res << endl;
}