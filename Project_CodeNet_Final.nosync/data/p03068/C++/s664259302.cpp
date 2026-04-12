#include <bits/stdc++.h>
#include <time.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define loop(i, a, b) for (int i = a; i < (int)(b); i++)


int main() {
    int N, K;
    cin >> N;
    string S;
    cin >> S;
    cin >> K;

    char c = S[K - 1];
    string ans = "";
    for (char d : S) {
        if (c == d) {
            ans += c;
        } else {
            ans += "*";
        }
    }
    cout << ans << endl;
    return 0;
}