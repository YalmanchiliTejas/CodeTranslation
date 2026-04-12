#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

typedef pair<int, int> P;
ll modnum = 1e9+7;



int main() {
    int n; cin >> n;
    vector<int> ans;
    rep(i, n) {
        int a; cin >> a;
        if(ans.size() == 0 || ans[ans.size()-1] >= a) {
            ans.push_back(a);
        } else {
            int l = 0, r = ans.size()-1;
            while(r-l > 1) {
                int mid = l + (r - l) / 2;
                if(a > ans[mid]) r = mid;
                else l = mid;
            }
            if(l == 0 && a > ans[0]) ans[l] = a;
            else ans[r] = a;
        }
//
//        cout << "C" << endl;
//        rep(j, ans.size()) {
//            cout << ans[j] << endl;
//        }

    }

    cout << ans.size() << endl;

    return 0;
}
