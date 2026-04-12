#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N, cin >> S, cin >> K;
    char k = S[K - 1];
    for (int i = 0; i < N; ++i) cout << (S[i] == k ? S[i] : '*');
    cout << endl;
    return 0;
}