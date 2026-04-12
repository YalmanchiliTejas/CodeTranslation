#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <tuple>
#include <climits>
#include <sstream>
using namespace std;

static const unsigned long long int MOD = 1000000007LL;

int n, res = 0;
int a[100001], b[100001];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = 1000000001;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int *id = upper_bound(b, b + n, a[i]);
        int pos = (int)(id - b);
        b[pos] = a[i];
        if (pos > res)
        {
            res = pos;
        }
    }

    cout << res + 1 << endl;

    return 0;
}