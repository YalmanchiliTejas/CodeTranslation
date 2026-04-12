#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, X, M;
    cin >> N >> X >> M;

    vector<pair<long long, long long>> first(M, make_pair(0, -1));

    long long current = 0;
    for (long long i = 1; i <= N; i++)
    {
        X %= M;
        current += X;
        if (first[X].second == -1)
        {
            first[X] = make_pair(current, i);
        }
        else
        {
            long long period = i - first[X].second;
            long long loop = max(0ll, (N - i) / period - 1);
            current += loop * (current - first[X].first);
            i += loop * period;
        }
        X *= X;
    }
    cout << current << endl;
}
