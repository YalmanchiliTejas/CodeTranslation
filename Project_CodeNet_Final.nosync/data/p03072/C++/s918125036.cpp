#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];

    bool ngFlg = true;
    int rst = 0;
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(H[i] < H[j]) {
                ngFlg = false;
                break;
            }
        }
        if(ngFlg) rst++;
        ngFlg = true;
    }
    cout << rst+1 << endl;
}