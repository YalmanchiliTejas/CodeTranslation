#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int H[100];
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    int H_M = H[0];
    int Count = 1;
    for (int i = 1; i < N; i++) {
        if (H[i] > H_M) {
            H_M = H[i];
            Count++;
        }
        else if (H[i] == H_M) {
            Count++;
        }
    }
    
    cout << Count << endl;
}