#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int K;
    cin >> K;

    char x = S[K - 1];
    for (int i = 0; i < S.size(); i++) {
        if (S[i] != x) {
            S[i] = '*';
        }
    }
    cout << S << endl;
}