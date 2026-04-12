#include<iostream>
#include<vector>

using namespace std;

int main() {
    
    int N, max=0, count=0;
    cin >> N;

    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    for (int i = 0; i < N; i++) {
        if (max <= H[i]) {
            max = H[i];
            count++;
        }
    }

    cout << count;

    return 0;
}