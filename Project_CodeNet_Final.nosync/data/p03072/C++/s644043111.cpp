#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;cin >> N;
    int H[N] = {};
    for (int i = 0;i < N;i++){
        cin >> H[i];
    }
    int M[N] = {};
    M[0] = H[0];
    int sum = 1;
    for (int i = 1;i < N;i++){
        if (H[i] >= M[i - 1]){
            sum++;
            M[i] = H[i];
        }
        else M[i] = M[i - 1];
    }
    cout << sum << endl;
}