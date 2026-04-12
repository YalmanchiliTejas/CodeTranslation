#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    multiset<int> mapA;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        auto itr = mapA.lower_bound(A);
        if (itr != mapA.begin()) {
            --itr;
            mapA.erase(itr);
        }
        mapA.emplace(A);
    }

    cout << mapA.size() << endl;
    return 0;
}
