#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    multiset<int> S;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        auto b = S.lower_bound(a);
        if (b != S.begin()) S.erase(prev(b));
        S.insert(a);
    }
    printf("%d\n", (int)S.size());
    return 0;
}
