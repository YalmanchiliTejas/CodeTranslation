#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

void solve(long long N, long long X, long long M) {
    vector<long long> S;
    map<long long, int> pos;
//    cout << "STOP" << endl;
    while (true) {
        if (S.size() == N) {
            cout << accumulate(S.begin(), S.end(), 0ll) << endl;
            return;
        }
        if (pos.count(X)) {
            int currentIndex = S.size();
            int lastIndex = pos[X];
            long long ans = 0;
            for (int i = 0; i < lastIndex; i++) {
//                cout << S[i] << " ";
                ans += S[i];
            }
            long long lsum = 0;
//            cout << "[";
            for (int i = lastIndex; i < currentIndex; i++) {
//                cout << S[i] << " ";
                lsum += S[i];
            }
            long long R = N - lastIndex;

            for (int i = 0; i < R % (currentIndex - lastIndex); i++) {
                ans += S[lastIndex + i];
            }
            ans += (R / (currentIndex - lastIndex)) * lsum;

//            cout << "]" << endl;
            cout << ans << endl;
            break;
        } else {
            pos[X] = S.size();
            S.push_back(X);
            X = (X * X) % M;
        };
    }

}

int main() {
    long long N;
    scanf("%lld", &N);
    long long X;
    scanf("%lld", &X);
    long long M;
    scanf("%lld", &M);
    solve(N, X, M);
    return 0;
}
