#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define rt return
using dbl = double;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vi a(n);
        deque<int> b;
        rep(i, n)cin >> a[i];
        b.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if ((n % 2 == 0 && i % 2 == 1) || (n % 2 == 1 && i % 2 == 0)) {
                b.push_front(a[i]);
            }
            else {
                b.push_back(a[i]);
            }
        }
        rep(i, n) {
            cout << b[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
}
