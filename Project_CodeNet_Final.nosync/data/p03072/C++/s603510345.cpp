#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];
    
    int res = 0;
    int current = 0;
    for (int i = 0; i < N; ++i) {
        if (H[i] >= current) ++res;
        if (current < H[i]) current = H[i];
    }
    cout << res << endl;
}
