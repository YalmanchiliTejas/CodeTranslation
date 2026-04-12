#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int N; cin >> N;
    vector<pair<int, int>> A(N);
    int Rmin, Rmax, Bmin, Bmax;
    Rmin = Bmin = 1e9;
    Rmax = Bmax = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        if (A[i].first > A[i].second) swap(A[i].first, A[i].second);
        Rmin = min(Rmin, A[i].first), Rmax = max(Rmax, A[i].first);
        Bmin = min(Bmin, A[i].second), Bmax = max(Bmax, A[i].second);
    }
    sort(begin(A), end(A));
    Int ans = (Int)(Rmax - Rmin) * (Bmax - Bmin);
    int m = 1e9;
    for (int i = 0; i < N-1; i++) {
        m = min(m, A[i].second);
        Rmin = min(m, A[i+1].first);
        Rmax = max(Rmax, A[i].second);
        Bmin = min(Bmin, A[i].first);
        ans = min(ans, (Int)(Rmax - Rmin) * (Bmax - Bmin));
        if (Rmin != A[i+1].first) break;
    }
    cout << ans << '\n';
    return 0;
}