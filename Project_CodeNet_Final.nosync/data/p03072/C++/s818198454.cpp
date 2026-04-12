#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N;
    cin >> N;
    int pre = 0;
    int sum = 0;
    rep(i,N) {
        int H;
        cin >> H;
        if (pre <= H) sum++;
        pre = max(pre, H);
    }
    cout << sum << endl;
}