#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned ll
#define all(x) x.begin(), x.end()
const ll MOD = 1e9 + 7;
const int MAX = 5000010;
int lastInc[MAX] = {};

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &x : a)
        cin >> x;
    int curr_max = a[0];
    int cnt = 1;
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] >= curr_max)
            cnt++;
        curr_max = max(curr_max, a[i]);
    }
    cout << cnt << endl;
}