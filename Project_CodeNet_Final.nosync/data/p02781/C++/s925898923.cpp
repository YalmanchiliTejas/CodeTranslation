#include<bits/stdc++.h>
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

// 9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
// 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

int main() {
    string n; cin >> n;
    int k; cin >> k;

    // 特殊パターン対応
//    if(n.size() == k) {
//        ll ans = 0;
//        int already_use = 0;
//        rep(i, n.size()) {
//            FOR(j,1,n[i]-'0') {
//                int already_use2 = already_use;
//                if(j > 0) already_use2++;
//                //if(already_use2 > k) continue;
//                // 計算
//                int select_num = k-already_use2;
//                ll tmp_cross = 1;
//                rep(k, select_num) {
//                    tmp_cross *= n.size()-i-1-k;
//                }
//                ll tmp_div = 1;
//                rep(k, select_num) {
//                    tmp_div *= select_num-k;
//                }
//                ll tmp = tmp_cross/tmp_div;
////            cout << tmp << endl;
////            cout << " - " << endl;
////            //cout << tmp*pow(9,select_num) << endl;
//////            cout << i << endl;
//////            cout << tmp << endl;
//                ans += tmp*pow(9,select_num);
//            }
//            already_use++;
//            if(already_use >= k) {
//                if()
//                break;
//            }
//        }
//
//        cout << ans << endl;
//        return 0;
//    }

    ll ans = 0;
    int already_use = 0;
    rep(i, n.size()) {
        bool flag = false;
        rep(j, n[i]-'0') {
            flag = true;
            if(i == n.size()-1 && already_use+1 == k) {
                ans += n[i]-'0';
                cout << ans << endl;
                return 0;
            }
            int already_use2 = already_use;
            if(j > 0) already_use2++;
            //if(already_use2 > k) continue;
            // 計算
            int select_num = k-already_use2;
            ll tmp_cross = 1;
            rep(l, select_num) {
                int a = n.size()-i-1-l;
                tmp_cross *= a;
            }
            ll tmp_div = 1;
            rep(l, select_num) {
                tmp_div *= select_num-l;
            }
            ll tmp = tmp_cross/tmp_div;
//            cout << tmp << endl;
//            cout << " - " << endl;
//            //cout << tmp*pow(9,select_num) << endl;
////            cout << tmp << endl;
            ans += tmp*pow(9,select_num);
        }
        if(flag) already_use++;
        if(already_use >= k) {
            if(n[i]-'0' != 0) {
                ans++;
            }
            break;
        }
    }

    cout << ans << endl;

    return 0;
}