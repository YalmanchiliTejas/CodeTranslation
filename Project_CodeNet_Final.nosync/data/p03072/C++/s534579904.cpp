#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int height[N];
    for (int i = 0; i < N; ++i) {
        cin >> height[i];
    }

    int tmp = 0;
    int ans = 1;
    bool flag = false;
    for (int j = 1; j < N; ++j) {
        for (int i = tmp; i < j; ++i) {
            if (height[j] < height[i]) {
                flag = false;
                break;
            }
            flag = true;
        }
        if (flag) {
            tmp = j;
            ans++;
        }
    }
    cout << ans;
}