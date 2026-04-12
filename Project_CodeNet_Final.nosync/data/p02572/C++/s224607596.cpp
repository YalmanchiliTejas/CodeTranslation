#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <math.h> // sqrt
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <iomanip> // setprecision
#include <bitset> // bitset
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

ll mod = 1000000007;

int main() {
    int N;
    cin >> N;
    vll data(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    vll sum(N, 0);
    ll ans = 0, suma = 0;
    for (int i = 0; i < N; i++) {
        suma += data[i];
        suma %= mod;
        sum[i] = suma;
    }
    for (int i = 0; i < N - 1; i++) {
        ll b = sum[N - 1] - sum[i];
        if (b < 0) {
            b += mod;
        }
        ll a = data[i] * b % mod;
        ans += a;
        ans %= mod;
    }
    cout << ans << endl;
}
