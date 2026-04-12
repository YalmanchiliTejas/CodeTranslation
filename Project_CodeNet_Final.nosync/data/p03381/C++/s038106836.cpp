#include <bits/stdc++.h>
using ll = long long int;
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> X(N, pair<int, int>(0, 0));
    for (int i = 0; i < N; i++)
    {
        cin >> X[i].first;
        X[i].second = i;
    }
    sort(X.begin(), X.end());
    int a = X[N / 2 - 1].first, b = X[N / 2].first;
    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (i < N / 2)
        {
            ans[X[i].second] = b;
        }
        else
        {
            ans[X[i].second] = a;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}