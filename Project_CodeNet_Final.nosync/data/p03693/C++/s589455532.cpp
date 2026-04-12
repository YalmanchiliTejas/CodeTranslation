#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <tuple>
#include <cstring>

#define INF 100000000

using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    cout << ((stoi(a + b + c) % 4 == 0) ? "YES\n" : "NO\n");

    return 0;
}
