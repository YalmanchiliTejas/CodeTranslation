#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int i = 0;
    int ans = 0;
    int tmp = 0;

    while (i < N) {
        int H;
        cin >> H;

        if(H >= tmp) {
            ans++;
            tmp = H;
        }
        i++;
    }

    cout << ans << endl;

    return 0;
}