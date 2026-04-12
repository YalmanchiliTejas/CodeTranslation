#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <random>

using namespace std;

long long A[100005];
long long N;

int main()
{
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        cin >> A[i];
    }

    long long sum = 0;

    sort(A, A + N);

    long long l, r, lc, rc;

    l = A[0];
    r = A[0];

    lc = 1;
    rc = N - 1;

    long long t[4];

    for (int i = 1; i < N;i++)
    {
        t[0] = abs(A[lc] - l);
        t[1] = abs(A[lc] - r);
        t[2] = abs(A[rc] - l);
        t[3] = abs(A[rc] - r);

        int d = std::max_element(t, t + 4) - t;

        //cout << i << ':' << d << ' ' << t[d] << endl;

        if(d == 0)
        {
            sum += t[0];
            l = A[lc];
            lc++;
        }
        if (d == 1)
        {
            sum += t[1];
            r = A[lc];
            lc++;
        }
        if (d == 2)
        {
            sum += t[2];
            l = A[rc];
            rc--;
        }
        if (d == 3)
        {
            sum += t[3];
            r = A[rc];
            rc--;
        }
    }

    cout << sum << endl;

    return 0;
}