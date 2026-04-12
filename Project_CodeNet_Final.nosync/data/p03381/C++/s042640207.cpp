#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        Y[i] = X[i];
    }
    sort(Y.begin(), Y.end());
    int mid = Y[N / 2 - 1], next = Y[N / 2];
    for (int i = 0; i < N; i++) {
        cout << (X[i] > mid? mid: next) << endl;
    }
}

