#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, k, n) for(int i = k; i < (int)(n); i++)
using ll = long long;

int main() {
    int n;
    const int price = 800;
    cin >> n;
    int x = n * price;
    int y = (n / 15) * 200;
    cout << x - y << endl;

    return 0;
}