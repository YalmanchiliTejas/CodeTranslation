// Shift-JIS（シフトジス）

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    int v = 0;
    int h = 0;
    for (int i = 0; i < N; i++) {
        if (h <= H[i]) {
            v++;
            h = H[i];
        }
    }
    cout << v << endl;
}