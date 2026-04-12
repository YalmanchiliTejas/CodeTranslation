#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int K, N;
    string S;
    cin >> N >> S >> K;
    
    char c = S[K - 1];
    for (char& cc: S) {
        if (cc != c) {
            cc = '*';
        }
    }

    cout << S << endl;

    return 0;
}