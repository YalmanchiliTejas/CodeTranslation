#include "bits/stdc++.h"

using namespace std;


int main()
{
    size_t a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    size_t X = min(x, y);
    size_t Y = max(x, y);
    size_t A = x <= y ? a : b;
    size_t B = x <= y ? b : a;

    std::vector<size_t> cands{
        A * X + B * Y,
        2 * c * X + B * (Y - X),
        2 * c * Y
    };

    cout << *min_element(cands.begin(), cands.end()) << endl;

    return 0;
}
