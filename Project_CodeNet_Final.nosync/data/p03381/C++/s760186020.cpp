#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> x(n);
    for (auto& i : x) cin >> i;

    vector<int> y = x;
    sort(y.begin(), y.end());

    int a = y[n / 2 - 1], b = y[n / 2];
    for (int i : x) cout << (i <= a ? b : a) << endl;

    return 0;
}
