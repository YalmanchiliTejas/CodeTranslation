#include <bits/stdc++.h>
#include <numeric>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define pr pair<int, int>

using namespace std;

const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;

//#define DEBUG

#ifdef DEBUG
#define PRINT(A) std::cout << (#A) << ":" << (A) << std::endl;
#else
#define PRINT(A)
#endif

template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// int a[10010][10010], b[1000];
// int dp[10010][3];

int S[10][1000];

void chAllVal(int before, int after, int h, int w) {
    rep(i, h * w) {
        if (S[i / w][i % w] == before) {
            S[i / w][i % w] = after;
        }
    }
}

int main() {

    string S; cin >> S;
    if(S == "AAA" || S == "BBB"){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

    return 0;
}
