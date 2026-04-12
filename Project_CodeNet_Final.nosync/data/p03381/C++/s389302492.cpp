#include <bits/stdc++.h>

using namespace std;

int n;
int A[200000], S[200000];
int L, R;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        S[i] = A[i];
    }
    sort(S, S+n);
    L = S[n/2 -1];
    R = S[n/2];

    for (int i = 0; i < n; i++) {
        if (A[i] <= L) cout << R << endl;
        else cout << L << endl;
    }
}
