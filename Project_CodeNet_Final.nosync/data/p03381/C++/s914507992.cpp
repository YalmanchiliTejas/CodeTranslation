#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int
main()
{
    int n;
    cin >> n;

    vector<int> x(n), sx(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sx[i] = x[i];
    }
    sort(sx.begin(), sx.end());
    int m1 = sx[n / 2 - 1];
    int m2 = sx[n / 2];
    for (int i = 0; i < n; i++) {
        if (x[i] <= m1)
            cout << m2 << endl;
        else
            cout << m1 << endl;
    }
}
