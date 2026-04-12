#include <iostream>
using namespace std;

int main() {
    int N;
    string S;
    int K;
    cin >> N >> S >> K;

    for (int i = 0; i < N; i++) {
        if (S[i] != S[K - 1]) {
            S[i] = '*';
        }
    }

    cout << S << endl;
    return 0;
}