#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    long long x;
    long long m;
    vector<int> beforeCycle;
    int beforeCycleSize = 0;
    long long beforeCycleSum = 0;
    int cycleSize;
    long long totalSum = 0;

    cin >> n >> x >> m;

    vector<int> remainderIndices(m, -1);

    while (remainderIndices[x] == -1) {
        beforeCycle.push_back(x);

        remainderIndices[x] = beforeCycleSize++;
        beforeCycleSum += x;
        x = x * x % m;
    }

    cycleSize = beforeCycleSize - remainderIndices[x];

    if (n <= cycleSize) {
        for (int i = 0; i < n; i++) {
            totalSum += beforeCycle[i];
        }
    } else {
        long long cycleSum = 0;
        
        for (int i = remainderIndices[x]; i < beforeCycleSize; i++) {
            cycleSum += beforeCycle[i];
        }

        totalSum = beforeCycleSum;
        n -= beforeCycleSize;
        totalSum += (n / cycleSize) * cycleSum;
        n %= cycleSize;

        for (int i = 0; i < n; i++) {
            totalSum += beforeCycle[remainderIndices[x] + i];
        }
    }

    cout << totalSum << endl;

    return 0;
}
