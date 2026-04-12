#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    int x = 800 * N;
    int y = 200 * (N / 15);

    cout << x - y << endl;
    return 0;
}