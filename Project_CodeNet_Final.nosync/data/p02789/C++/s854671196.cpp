#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cctype>
const int INT_INF = 1000000000;                 // 10^9
const long long LONG_INF = 1000000000000000000; // 10^18

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    if (n == m)
    {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}