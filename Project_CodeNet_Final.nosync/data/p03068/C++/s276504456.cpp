
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <array>
#include <cmath>

using namespace std;

using ll = long long int;

int main() {

    int N, K;
    string S;

    cin >> N;
    cin >> S;
    cin >> K;

    char tgt = S.at(K-1);
    for (auto & ch : S) {
        if (ch != tgt) ch = '*';
    }

    cout << S;

    return 0;
}

