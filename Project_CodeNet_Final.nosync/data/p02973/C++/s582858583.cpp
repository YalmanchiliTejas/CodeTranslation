#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define rloop(n, i) for(int i=n;i;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;

int n;
V<ll> A;

int main() {
    cin >> n;
    A.resize(n);
    loop (n, i) cin >> A[i];

    V<int> B = { - 1 };
    loop (n, i) {
        if (B[B.size() - 1] >= A[i]) {
            B.push_back(A[i]);
        } else {
            auto itr = upper_bound(B.begin(), B.end(), A[i], greater<int>());
            *itr = A[i];
        }

        // for (auto k : B) {
        //     cout << k << " ";
        // }
        // cout << endl;
    }

    cout << B.size() << endl;
    return 0;
}

