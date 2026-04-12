#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int cnt = N/15;
    cout << N*800 - cnt*200 << endl;
    return 0;
}