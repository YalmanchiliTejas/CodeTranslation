#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;


int main() {
    int N; cin >> N;
    string S; cin >> S;
    int K; cin >> K;
    char c = S[K-1];
    for (int i = 0; i < N; ++i) {
        if (S[i] != c) cout << '*';
        else cout << S[i];
    }
    cout << endl;
}
