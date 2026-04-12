#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int N;

int main() {
    cin >> N;
    int mx = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        if (h >= mx) {
            cnt++;
            mx = h;
        }
    }
    cout << cnt << endl;
}



