#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];
    
    int res = 0;
    int current_max = 0;
    for (int i = 0; i < N; ++i) {
        // i 番目が、i-1 番目以前の最大値以上だったらカウント
        if (H[i] >= current_max) ++res;

        // これまでの最大値を新たに更新する
        if (current_max < H[i]) current_max = H[i];
    }
    cout << res << endl;
}