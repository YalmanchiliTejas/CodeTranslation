#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N; cin >> N;
    int h[N]; for(int i = 0;i < N; ++i) cin >> h[i];
    int res = 1;
    for (int i = 1; i < N; ++i) {
        bool f = true;
        for (int j = 0; j < i; j++) {
            f &= h[j] <= h[i]; 
        }
        if (f) ++res;
    }
    cout << res << endl;
}
