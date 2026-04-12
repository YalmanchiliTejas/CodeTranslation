#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n, mx_l, mx_r;
    scanf("%d", &n);
    vector<int> md(n);
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x[i].first);
        x[i].second = i;
    }
    sort(x.begin(), x.end());
    mx_l = x[n / 2 - 1].first;
    mx_r = x[n / 2].first;
    for (int i = 0; i < n / 2; ++i)
    {
        md[x[i].second] = mx_r;
    }
    for (int i = n / 2; i < n; ++i)
    {
        md[x[i].second] = mx_l;
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", md[i]);
    }
}

