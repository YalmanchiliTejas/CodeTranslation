#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        int sum{0};
        int max_{-1};
        int min_{10000};
        for (int i = 0; i < n; ++i) {
            int s;
            cin >> s;
            sum += s;
            max_ = max(max_, s);
            min_ = min(min_, s);
        }
        cout << ((sum - max_ - min_) / (n - 2)) << endl;
    }
}