#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    vector<int> S(N, -1);
    rep(i, N) {
        int left = -1;
        int right = N;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (S[mid] < A[i]) right = mid;
            else left = mid;
        }
        S[right] = A[i];
    }
    rep(i, N) {
        if (S[i] == -1) {
            cout << i << endl;
            return 0;
        }
    }
    cout << N << endl;
    return 0;
}
