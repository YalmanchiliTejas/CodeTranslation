 #include <iostream>

#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll MAX { 200010 };
ii xs[MAX];
int medians[MAX];

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> xs[i].first;
        xs[i].second = i;
    }

    sort(xs, xs + N);

    int limit = (N - 1)/2;

    for (int i = 0; i < N; ++i)
        medians[xs[i].second] = (i <= limit) ? xs[N/2].first : xs[limit].first;

    for (int i = 0; i < N; ++i)
        printf("%d\n", medians[i]);

    return 0;
}
