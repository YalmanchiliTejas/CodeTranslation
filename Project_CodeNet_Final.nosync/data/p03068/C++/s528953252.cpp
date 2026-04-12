#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> S >> K;
    string ans = "";
    char letter = S[K - 1];
    for (int i = 0; i < N; i++) {
        if (S[i] == letter) {
            ans += letter;
        } else {
            ans += "*";
        }
    }
    cout << ans << endl;
}