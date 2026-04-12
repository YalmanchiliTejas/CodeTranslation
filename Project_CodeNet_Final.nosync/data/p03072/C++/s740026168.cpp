#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

int main()
{
    int n, ma = -1;
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (ma <= a)
        {
            cnt++;
            ma = a;
        }
    }
    cout << cnt << endl;
}
