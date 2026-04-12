
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int num = 0;
    int cur_h = 0;
    while (N--) {
        int H;
        cin >> H;
        if (cur_h <= H) {
            cur_h = H;
            num++;
        }
    }
    cout << num << '\n';



    return 0;
}
