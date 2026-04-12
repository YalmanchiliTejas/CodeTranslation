#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<int> hi(n, 0);
    rep(i, n)
    {
        if (i == 0)
            hi[i] = 0;
        else if (i == 1)
            hi[i] = h[0];
        else
            hi[i] = max(hi[i - 1], h[i - 1]);
    }
    int count = 0;
    rep(i, n)
    {
        if (h[i] >= hi[i])
            count++;
    }
    cout << count << endl;
    return 0;
}