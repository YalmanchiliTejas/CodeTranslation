#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <queue>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    cout << ((r * 100 + g * 10 + b) % 4 == 0 ? "YES" : "NO") << endl;

    return 0;
}
