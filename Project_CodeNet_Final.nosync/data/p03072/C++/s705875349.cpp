#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];
    
    vector<int> M(N);
    M[0] = H[0];
    for (int i = 1; i < N; ++i) {
        if (H[i] < M[i-1]) M[i] = M[i-1];
        else M[i] = H[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (M[i] == H[i]) ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
