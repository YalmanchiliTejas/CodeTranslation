//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

 
int main() {
    int n;
    cin >> n;
    vi a(26);
    rep(i, n) {
        string S;
        cin >> S;
        vi a_(26);
        rep(j, S.size()) {
            if(!i) a[S[j]-'a']++;
            a_[S[j]-'a']++;
        }
        rep(j, 26) {
            a[j] = min(a[j], a_[j]);
        }
        
    }

    string ans;
    rep(i, 26) {
        rep(j, a[i]) {
            ans += i + 'a';
        }
    }

    cout << ans << endl;
}