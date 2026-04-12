#include <bits/stdc++.h>
using namespace std;
void init_ios() {ios_base::sync_with_stdio(false); cin.tie(nullptr);}

int N;

int main() {
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) cin >> a;

    vector<pair<int, int>> b;
    for (int i = 0; i < N; ++i) b.emplace_back(A[i], i);

    sort(b.begin(), b.end());

    vector<int> c(N);
    for (int i = 0; i < N; ++i) {
        c[b[i].second] = i;
    }

    for (int i = 0; i < N; ++i) {
        int x = c[i] < N / 2 ? b[N/2].first : b[N/2-1].first;
        cout << x << endl;
    }

    return 0;
}
