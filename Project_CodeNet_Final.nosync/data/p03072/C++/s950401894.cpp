#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];

    int res = 1, max_height = H[0];
    for (int i = 1; i < N; i++) {
        if (H[i] >= max_height) {
            max_height = H[i];
            res++;
        }
    }
    cout << res << endl;
    return 0;
}