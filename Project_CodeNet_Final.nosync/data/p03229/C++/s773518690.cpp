#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)  cin >> A[i];
    sort(A.begin(), A.end());
    
    long long ans = 0;
    if (N % 2) {
        if (A[N / 2] - A[N / 2 - 1] > A[N / 2 + 1] - A[N / 2]) {
            for(int i = 0; i < N / 2; i++) {
                ans += 2 * (A[N / 2 + i + 1] - A[i]);
            }
            ans += A[N / 2] - A[N / 2 + 1];
        } else {
            for(int i = 0; i < N / 2; i++) {
                ans += 2 * (A[N / 2 + i + 1] - A[i]);
            }
            ans += A[N / 2 - 1] - A[N / 2];
        }
    } else {    //Nが偶数のとき
        for (int i = 0; i + 1 < N / 2; i++) {
            ans += 2 * (A[N / 2 + i + 1] - A[i]);
        }
        ans += A[N / 2] - A[N / 2 - 1];
    }
    cout << ans << endl;
}