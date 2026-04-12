#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    int max_h = H[0];
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (H[i] >= max_h) {
            max_h = H[i];
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
