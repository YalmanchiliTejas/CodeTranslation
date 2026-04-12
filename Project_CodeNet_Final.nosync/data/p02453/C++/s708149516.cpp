#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    int i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        cout << distance(a, lower_bound(a, a + n, k)) << endl;
    }
    return 0;
}
