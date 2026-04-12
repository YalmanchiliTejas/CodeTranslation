#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
typedef pair<int, int> P;

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*
#define cin ifs
#define cout ofs
ifstream ifs("in.txt");
ofstream ofs("out.txt");
//*/

int N;
int X[220000],X_m[220000];

signed main() {
    int l, r;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        X_m[i] = X[i];
    }
    sort(X, X + N);
    l = X[N / 2 - 1];
    r = X[N / 2];
    for (int i = 0; i < N; i++) {
        if (X_m[i] <= l) {
            cout << r << endl;
        } else {
            cout << l << endl;
        }
    }
    return 0;
}