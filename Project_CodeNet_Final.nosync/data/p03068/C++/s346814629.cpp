#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    string S;
    while (cin >> N >> S >> K) {
        char c = S[K-1];
        for (auto &s : S) if (s != c) s = '*';
        cout << S << endl;
    }
}
