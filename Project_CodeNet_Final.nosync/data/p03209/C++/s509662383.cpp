#include <iostream>
#include <vector>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << " = " << (x) << endl

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

ll c[100];

ll burger(int n, ll x) {
    if (n == 0) return 1;
    ll len = (1ll << (n + 1)) - 3;
    ll num = (1ll << n) - 1;
    if (x == 1) return 0;
    else if (x <= len + 1) return burger(n - 1, x - 1);
    else if (x == len + 2) return num + 1;
    else if (x <= (len + 1) * 2) return num + 1 + burger(n - 1, x - len - 2);
    else return num * 2 + 1;
}


int main() {
    int n;
    ll x;
    cin >> n >> x;
    cout << burger(n, x) << endl;
}