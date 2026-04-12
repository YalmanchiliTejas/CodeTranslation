#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define ifaxb(a, x, b) if (a < x && x < b)  // 比較は昇順
#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vss vector<vs>
#define all(x) x.begin(), x.end()
#define pi 3.1415926536
#define ff first
#define ss second
#define pq priority_queue
#define ipair pair<int, int>
#define spair pair<string, string>
#define lpair pair<LL, LL>
#define MP make_pair
#define INF 2147483647
#define _INF -2147483647
#define MM multimap
#define PB push_back
#define MAXN 100004
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vi H(N);

    int high = 0;
    int ans = 0;
    rep(i, 0, N) {
        cin >> H[i];
        if (high <= H[i]) {
            high = H[i];
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
