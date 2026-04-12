#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define REP(i,a,b) for(int i=int(a);i<int(b);i++)

using namespace std;

typedef long long int lli;

int main () {
    int N;
    cin >> N;
    vector<lli> A(N);
    REP (i, 0, N) cin >> A[i];
    lli ans = 0;
    bool run = true;
    while (run) {
        run = false;
        lli sum = 0;
        REP (i, 0, N) {
            sum += A[i] / N;
        }
        REP (i, 0, N) {
            A[i] = A[i] - A[i] / N * (N + 1) + sum;
            if (A[i] >= N)  run = true;
        }
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}
