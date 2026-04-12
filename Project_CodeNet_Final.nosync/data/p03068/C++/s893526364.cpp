#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int K;
    cin >> K;

    char c = S[K - 1];

    for (int i = 0; i < S.size(); i++) {
        if (S[i] != c) {
            S[i] = '*';
        }
    }

    cout << S << endl;
    return 0;
}
