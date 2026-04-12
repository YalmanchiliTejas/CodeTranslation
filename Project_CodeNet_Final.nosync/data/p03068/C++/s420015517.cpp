#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main() {
    int N;
    string S;
    int K;
    cin >> N;
    cin >> S;
    cin >> K;
    char s = S[K-1];
    for (int i = 0; i < N; i++) {
        if (S[i] != s) S[i] = '*';
    }
    cout << S << '\n';
}

