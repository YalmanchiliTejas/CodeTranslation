#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

inline void deBugMode() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE
}

inline void optimizeIt() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

inline int ABS(const int &x) {
    return max(x, -x);
}

const int NMax = 1e5 + 5;
const int LIM = 1e5;
const int MOD = 1000000007;

int main(){
    //deBugMode();
    optimizeIt();

    char c;
    cin >> c;

    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        cout << "vowel";
    } else {
        cout << "consonant";
    }

    return 0;

}
