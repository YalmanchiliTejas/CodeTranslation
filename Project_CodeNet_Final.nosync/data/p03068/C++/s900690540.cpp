#include <iostream>
#include <cmath>
using namespace std;

int main() {
        int N, K;
        string S;
        cin >> N >> S >> K;

        char base = S[K-1];
        for (int i = 0; i < N; ++i) {
                if (S[i] != base) {
                        S[i] = '*';
                }
        }
        cout << S << "\n";
        return 0;
}
