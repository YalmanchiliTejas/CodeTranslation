#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define INF 10000000000
#define MOD 1000000007

using namespace std;

int main()
{
    int N, x, y;
    cin >> N;
    x = 800 * N;
    y = 200 * (N / 15);
    cout << x - y << endl;

    return 0;
}
