#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#include <numeric>
#include <iomanip>

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }

    int max = 0;
    int ans = 0;

    rep(i, n)
    {
        if (h[i] >= max)
        {
            ans++;
            max = h[i];
        }
    }

    cout << ans << endl;
    
}