#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int N; cin >> N;
    vector<Int> A(N); for (auto& a : A) cin >> a;
    Int cnt = 0;
    Int minimum = *min_element(begin(A), end(A));
    for (auto& a : A) {
        a -= minimum;
        cnt += a / (N+1);
        a %= N+1;
    }
    for (auto& a : A) a += minimum + cnt;
    sort(rbegin(A), rend(A));
    vector<Int> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = A[i]+i;
        if (B[i] <= N-1) {
            cout << cnt + i << endl;
            return 0;
        }
    }
    int t = min_element(begin(B), end(B)) - begin(B);
    while (t--) {
        *max_element(begin(A), end(A)) -= N + 1;
        for (auto& a : A) a += 1;
        cnt++;
    }
    Int maximum = *max_element(begin(A), end(A));
    cout << cnt + (maximum - N + 1) * N << '\n';
    return 0;
}
