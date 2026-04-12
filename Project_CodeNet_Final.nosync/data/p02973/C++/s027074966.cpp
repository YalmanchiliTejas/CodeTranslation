#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> sq(N, -1);
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(sq.begin(), sq.end(), A[i]);
        it--;
        (*it) = A[i];
    }
    cout << distance(lower_bound(sq.begin(), sq.end(), 0), sq.end()) << endl;
    return 0;
}