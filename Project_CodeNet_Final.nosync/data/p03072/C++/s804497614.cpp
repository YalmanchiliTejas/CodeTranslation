#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    int sum = 1;
    int front = H[0];
    for (int i = 1; i < N; i++) {
        if (H[i] >= front) {
            sum++;
            front = H[i];
        }
    }
    cout << sum << endl;
}