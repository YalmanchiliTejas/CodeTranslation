#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> S >> K;
    char ch = S[K-1];
    rep(i, S.size()) {
        if (S[i] != ch) cout << "*";
        else cout << S[i];
    }
    cout << endl;
}
