#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ii {
    int a, b;
    bool operator < (ii o) const {
        return tie(a, b) < tie(o.a, o.b);
    }
};
struct iii {
    int a, b, c;
    bool operator < (iii o) const {
        return tie(a, b, c) < tie(o.a, o.b, o.c);
    }
};

const int MOD = 1000000007;
const int INF = 1000000000;
const int MAXN = 1000005;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;
    if (N >= 30) cout << "Yes\n";
    else cout << "No\n";
}
