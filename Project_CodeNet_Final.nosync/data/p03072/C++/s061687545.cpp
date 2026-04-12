#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> H(N);
    int res = 0;
    int flag = 0;
    for (int i = 0; i < N; i++) cin >> H[i];
    
    for (int i = N - 1; i >= 0; i--) {
        flag = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (H[i] < H[j]) flag = 1;
        }
        if (flag == 0) {
            res++;
        }
    }
    cout << res << endl;
    
}