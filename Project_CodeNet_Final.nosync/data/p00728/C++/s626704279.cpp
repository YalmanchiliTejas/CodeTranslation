#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    while (cin >> n, n) {
        int ans = 0, s;
        int max_s, min_s;

        max_s = 0;
        min_s = 1000;
        for (int i = 0; i < n; i++) {
            cin >> s;

            ans += s;
            max_s = max(max_s, s);
            min_s = min(min_s, s);
        }

        cout << (ans - max_s - min_s) / (n - 2) << endl;
    }

    return 0;
}