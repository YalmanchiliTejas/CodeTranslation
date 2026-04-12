#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int cnt = 0;
    int max_height = 0;
    for(int i = 0; i < N; i++) {
        if(H[i] >= max_height) {
            max_height = H[i];
            cnt++;
        }
    }
    cout << cnt << endl;

}
