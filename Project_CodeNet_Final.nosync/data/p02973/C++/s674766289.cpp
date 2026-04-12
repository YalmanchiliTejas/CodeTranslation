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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    deque<int> d;
    
    rep(i, n) {
        int p = lower_bound(all(d), a[i]) - d.begin();
        
        if (p == 0) {
            d.push_front(a[i]);
        }
        else {
            d[p - 1] = a[i];
        }
    }
    
    cout << sz(d) << endl;
    return 0;
}