#include "bits/stdc++.h"
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
using ull = unsigned long long;
using ll = long long;


int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    int max_h  = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        max_h = max(max_h, H[i]);
        if(max_h <= H[i]) sum++;
    }

    cout << sum << endl;
}