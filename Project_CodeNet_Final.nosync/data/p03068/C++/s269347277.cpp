#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int lli;
using namespace std;
// #define int long long int

signed main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int K;
    cin >> K;

    char t = S[K - 1];
    for (int i = 0; i < N; i++) {
        if (S[i] != t) S[i] = '*';
    }
    cout << S << endl;
    return 0;
}
