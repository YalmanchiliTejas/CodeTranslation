#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((b * 2 + c) % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
