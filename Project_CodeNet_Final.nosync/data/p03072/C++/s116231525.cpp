#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1e9)
#define PI (acos(-1))
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl


int main() {
    int N;  cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    int cnt = 0;
    for (int i=0; i<N; ++i) {
        bool flag = true;
        for (int j=0; j<i; ++j) {
            if (H[j] > H[i]) {
                flag = false;
            }
        }
        if (flag) ++cnt;
    }
    print(cnt);
}