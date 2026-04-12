#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i, n) for(int i = 0;i < n;i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(a) (a).begin(), (a).end()

using namespace std;

int main()
{
    int X, Y, Z; cin >> X >> Y >> Z;

    X -= Z;

    int i = 0;
    while(X >= 0)
    {
        X -= Y;
        X -= Z;
        i++;
    }

    cout << i - 1 << endl;

    return 0;
}