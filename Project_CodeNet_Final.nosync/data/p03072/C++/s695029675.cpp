#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define FOR(i, s, e) for (int (i) = (s); (i) < (e); (i)++)

int main() {
    int N; cin >> N;
    vector<int> H(N);
    FOR(i, 0, N) cin >> H[i];

    int count = 1;
    int maxi=H[0];

    FOR(i, 1, N) {
        if(H[i] >= maxi) {
            maxi= max(maxi, H[i]);
            count++;
        }
    }

    printf("%d\n", count);
}