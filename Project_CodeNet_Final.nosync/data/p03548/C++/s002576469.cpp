#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int tmp = Z;
    int cnt;
    while (tmp + Y + Z <= X)
    {
        tmp += Y + Z;
        cnt++;
    }
    cout << cnt << endl;
}
