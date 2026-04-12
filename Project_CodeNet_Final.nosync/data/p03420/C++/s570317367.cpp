#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

/*
#define cin ifs
#define cout ofs
ifstream ifs("in.txt");
ofstream ofs("out.txt");
//*/

signed main() {
    int N, K;
    cin >> N >> K;
    int ans = 0;
    for (int i = K + 1; i <= N; i++) {
        ans += N / i * (i - K);
        ans += max(0LL, N % i - K + 1);
    }
    if (K == 0) {
        ans -= N;
    }
    cout << ans << endl;
    return 0;
}