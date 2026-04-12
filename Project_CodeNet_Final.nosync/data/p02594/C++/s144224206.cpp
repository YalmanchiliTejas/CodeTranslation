#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define uint unsigned int
void DEBUG() {
    cout << "]\n";
}
template<typename H, typename...T> void DEBUG(H h, T... t) {
    cout << h;
    if(sizeof...(t))
        cout << ", ";
    DEBUG(t...);
}
#define debug(...) cout << "[LINE: " << __LINE__ << "] -> [" << #__VA_ARGS__ << " = ", DEBUG(__VA_ARGS__)



void solve() {
    int n;
    cin >> n;
    if(n>=30)
        puts("Yes");
    else
        puts("No");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}