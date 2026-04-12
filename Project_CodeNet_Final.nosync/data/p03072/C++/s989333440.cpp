#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
typedef long long ll;
namespace mp = boost::multiprecision;
using Mint = mp::cpp_int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = int(a); i < int(b); i++)
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(all(v)), v.end())
#define sort_g(v) sort(all(v), greater<int>())
#define dump(x) cerr << #x << ' ' << '=' << ' ' << x << endl

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H.at(i);

    int cnt = 0;
    rep(i, N) {
        if(i == 0) {
            cnt++;
        } else {
            bool flg = true;
            rep(j, i) {
                if(H.at(j) > H.at(i)) {
                    flg = false;
                    break;
                }
            }
            if(flg) cnt++;
        }
    }

    cout << cnt << endl;
}