#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;

int main()
{
    int N;
    cin >> N;
    cout << 800 * N - 200 * (N / 15) << endl;

    return 0;
}