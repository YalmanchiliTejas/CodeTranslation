#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <limits>
#include <queue>
#include <iomanip>
#include <deque>
#include <stack>
#include <cstdio>
#include <cmath>
#include <complex.h>
#include <cstdio>
#include <random>
#include <chrono>
#include <numeric>
#include <cassert>
#include <iso646.h>
#include <exception>
#include <stdexcept>

using namespace std;

typedef long long i64;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'C')
        {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
}