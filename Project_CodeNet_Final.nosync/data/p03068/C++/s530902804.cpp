#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int K, N;
    string S;
    cin >> N >> S >> K;
    for (int i=0;i<N;i++) {
        if (S[i] != S[K-1]) S[i] = '*';
    }
    cout << S << endl;

    return 0;
}