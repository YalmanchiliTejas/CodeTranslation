#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define INF (INT_MAX/3)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

using namespace std;

int main(void)
{
    int v = 0;

    REP(i, 3)
    {
        string c; cin >> c;
        v *= 10;
        v += atoi(c.c_str());
    }

    cout << ((v % 4 == 0) ? "YES" : "NO");

    return 0;

}

// 00:04:00
