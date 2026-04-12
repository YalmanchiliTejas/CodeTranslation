#include <bits/stdc++.h>

#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    using namespace std;
    int n;
    cin >> n;
    vector< vector<ll> > A(n);
    for(int i = 0; i < n; i++)
        A[i].resize(n - i);

    for(int i = 0; i < n; i++)
        cin >> A[0][i];

    for(int i = 1; i < n; i++)
        for(int j = 0; j < n - i; j++) {
            ll left = A[0][j] - A[i - 1][j + 1],
               right = A[0][j + i] - A[i - 1][j];
            if(left > right)
                A[i][j] = left;
            else
                A[i][j] = right;
        }

    cout << A[n - 1][0] << "\n";

    return 0;
}
