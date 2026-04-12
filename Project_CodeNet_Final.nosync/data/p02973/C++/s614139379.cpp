#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    cout << fixed << setprecision(10);
    
    int N; cin >> N;
    vector<int> A(N);
    // vector<bool> ped(N, false);
    rep(i, N) cin >> A[i];
    // int csum = 0;

    vector<int> sts;
    sts.emplace_back(A[0]);

    // A[i]未満の値があれば、それに上塗り、
    // A[i]未満の値がなければ、新たな色で追加する
    // stsにて降順で管理する
    repr(i, 1, N) {
        if (A[i] <= sts[sts.size()-1]) {
            // stsの最小の値 以下の場合
            sts.emplace_back(A[i]);
        } else {
            // stsの最小の値より大きい場合
            // なるべくA[i]に近くて、A[i]より小さい数を見つける
            int l = -1, r = sts.size();
            while (l + 1 < r) {
                int c = (l+r) / 2;
                if (sts[c] < A[i]) {
                    r = c;
                } else {
                    l = c;
                }
            }
            sts[r] = A[i];
        }
    }
    cout << sts.size() << endl;
    return 0;
}