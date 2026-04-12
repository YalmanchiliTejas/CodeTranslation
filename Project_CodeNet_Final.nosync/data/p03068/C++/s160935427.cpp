#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N;
    string S;
    int K;

    cin >> N;
    cin >> S;
    cin >> K;

    char c = S[K-1];

    string ret = "";
    for (int i = 0; i < N; i++) {
        if (S[i] == c) ret += S[i];
        else ret += "*";
    }

    cout << ret << endl;
    return 0;
}
