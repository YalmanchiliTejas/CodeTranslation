#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool cansee = true;
        for (int j = 0; j < i; j++) {
            if (h[i] < h[j]) {
                cansee = false;
                break;
            }
        }
        if (cansee) {
            ans++;
        }
    }
    cout << ans << endl;
}