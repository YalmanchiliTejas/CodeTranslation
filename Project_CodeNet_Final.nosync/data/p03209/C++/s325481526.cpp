#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<long> sump(51);
vector<long> sumb(51);
vector<long> suma(51);

long burger(long index, long x)
{
    if (suma[index] / 2 + 1 == x)
    {
        return sump[index] / 2 + 1;
    }
    else if (1 == x)
    {
        return 0;
    }
    else if (suma[index] == x)
    {
        return sump[index];
    }
    else if (suma[index] / 2 + 1 < x)
    {
        return sump[index] / 2 + 1 + burger(index - 1, x - suma[index] / 2 - 1);
    }
    else
    {
        return burger(index - 1, x - 1);
    }
}

int main()
{
    long N, X;
    cin >> N >> X;

    sump[0] = 1;
    sumb[0] = 0;
    for (int i = 1; i < N + 1; i++)
    {
        sump[i] = 2 * sump[i - 1] + 1;
        sumb[i] = 2 * sumb[i - 1] + 2;
        suma[i] = sump[i] + sumb[i];
    }

    //cout << sump[N] << "\n";

    cout << burger(N, X) << "\n";
}