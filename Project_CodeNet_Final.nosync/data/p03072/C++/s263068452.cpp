#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int N, h_max = -1, ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int h;
        cin >> h;
        if (h_max <= h) {
            ++ans;
            h_max = h;
        }
    }
    cout << ans << endl;
    return 0;
}
