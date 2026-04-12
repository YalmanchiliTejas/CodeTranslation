#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

int main()
{
    int n;

    cin >> n;
    V b;
    REP(i, n)
    {
        int a;
        cin >> a;
        if (i % 2 == 1)
        {
            b.insert(b.begin(), a);
        }
        else
        {
            b.push_back(a);
        }
    }

    REP(i, n)
    {
        if (n % 2 == 0)
            cout << b[i];
        else
            cout << b[n - 1 - i];

        if (i == n - 1)
            cout << endl;
        else
            cout << " ";
    }

    return 0;
}