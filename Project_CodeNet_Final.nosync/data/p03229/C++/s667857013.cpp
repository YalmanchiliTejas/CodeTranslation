#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int N;
int A[110000];
signed main() {
    cin >> N;
    for (int i = 0; i < N; i++)cin >> A[i];
    sort(A, A + N);
    int ans = 0;
    if (N % 2 == 0) {
        for (int i = 0; i < N / 2; i++)ans -= 2 * A[i];
        for (int i = N / 2; i < N; i++)ans += 2 * A[i];
        ans += A[N / 2 - 1] - A[N / 2];
    } else {
        int cur1 = 0;
        for (int i = 0; i < N / 2; i++)cur1 -= 2 * A[i];
        for (int i = N / 2; i < N; i++)cur1 += 2 * A[i];
        cur1 -= A[N / 2] + A[N / 2 + 1];
        int cur2 = 0;
        for (int i = 0; i < N / 2 + 1; i++)cur2 -= 2 * A[i];
        for (int i = N / 2 + 1; i < N; i++)cur2 += 2 * A[i];
        cur2 += A[N / 2] + A[N / 2 - 1];
        ans = max(cur1, cur2);

    }
    cout << ans << endl;

    return 0;
}