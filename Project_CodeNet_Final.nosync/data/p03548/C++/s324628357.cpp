#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    int answer = 0;
    answer = max(x - z, 0) / (y + z);
    cout << answer << endl;
}