#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;  cin >> N;
    vector<int> H(N);
    int n = 1;

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int high = H[0];

    for (int j = 1; j < N; ++j) {
        if(H[j] >= high){
            high = H[j];
            n++;
        }
    }
    cout << n << endl;

    return 0;
}