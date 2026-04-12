#include<iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int main()
{
    int n, h, max_so_far = 0, ans = 0;
    cin >> n;
    REP(i, n) {
        cin >> h;
        if (h >= max_so_far) ans++;
        max_so_far = max(h, max_so_far);
    }

    cout << ans << endl;

    return 0;
}