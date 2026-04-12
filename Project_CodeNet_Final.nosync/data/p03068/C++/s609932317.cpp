// Shift-JIS（シフトジス）

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    string S;
    char k;
    cin >> N >> S >> K;
    k = S[K - 1];
    for (int i = 0; i < N; i++) {
        if (S[i] != k) {
            S[i] = '*';
        }
    }
    cout << S << endl;
}