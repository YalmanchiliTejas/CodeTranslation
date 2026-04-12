#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).bigin(), (c).end())

int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    cout << (x - z) / (y + z) << endl;

    return 0;
}