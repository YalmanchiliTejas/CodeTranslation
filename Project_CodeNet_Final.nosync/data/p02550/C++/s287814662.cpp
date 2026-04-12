#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> remainderIndices(m, -1);

    vector<ll> beforeCycle;
    ll beforeCycleSum = 0, beforeCycleSize = 0;
    while (remainderIndices[x] == -1)
    {
        beforeCycle.push_back(x);

        remainderIndices[x] = beforeCycleSize++;
        beforeCycleSum += x;
        x = x * x % m;
    }

    ll cycleSize = beforeCycleSize - remainderIndices[x];

    ll totalSum = 0;
    if (n <= cycleSize)
        for (ll i = 0; i < n; i++)
            totalSum += beforeCycle[i];
    else
    {
        ll cycleSum = 0;

        for (ll i = remainderIndices[x]; i < beforeCycleSize; i++)
            cycleSum += beforeCycle[i];

        totalSum = beforeCycleSum;
        n -= beforeCycleSize;
        totalSum += (n / cycleSize) * cycleSum;
        n %= cycleSize;

        for (ll i = 0; i < n; i++)
            totalSum += beforeCycle[remainderIndices[x] + i];
    }

    cout << totalSum << endl;

    return 0;
}
