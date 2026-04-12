#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main()
{
    // 入力
    int N;
    cin >> N;

    vector<int> A(N);
    rep (i, N) {
        cin >> A[i];
    }

    vector<int> colors;
    rep (i, N) {
        if (i == 0) {
            colors.push_back(A[i]);
        } else {
            if (colors[colors.size() - 1] >= A[i]) {
                colors.push_back(A[i]);
            } else {
                bool newVector = true;

                rep (j, colors.size()) {
                    if (colors[j] < A[i]) {
                        colors[j] = A[i];
                        newVector = false;
                        break;
                    }
                }

                if (newVector) {
                    colors.push_back(A[i]);
                }
            }
        }
    }

    // 出力
    cout << colors.size() << endl;
    return 0;
}
