#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n), b;
    rep(i, n) cin >> a[i];
    
    rep(i, n) {
        if (i < ((n + 1) / 2)) {
            printf("%d%s", a[n - (i * 2 + 1)], ((i == (n - 1)) ? "\n" : " "));
        }
        else {
            printf("%d%s", a[(i - n / 2) * 2 - n % 2], ((i == (n - 1)) ? "\n" : " "));
        }
    }
    
    return 0;
}
