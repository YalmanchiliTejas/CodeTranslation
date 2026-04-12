#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;

#define MAX(x, y) ((x) < (y) ? (y) : (x))

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int *H = new int[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> H[i];
    }

    int h = H[0];
    int ret = 1;

    for (int i = 1; i < N; ++i)
    {
        if (H[i] >= h)
        {
            ++ret;
            h = H[i];
        }
    }

    cout << ret << "\n";

    return 0;
}

