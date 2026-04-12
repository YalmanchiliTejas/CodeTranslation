#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_N = 50;

int main(int argc, char const *argv[])
{
    int n, h[MAX_N];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int max_h = h[0], ans = 1;
    for (int i = 1; i < n; ++i) {
        if (h[i]>=max_h) {
            ans++;
            max_h = h[i];
        }
    }

    cout << ans << endl;

    return 0;
}