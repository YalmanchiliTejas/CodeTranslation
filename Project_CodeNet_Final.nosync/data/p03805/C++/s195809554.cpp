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

int main() {
    int N, M;
    cin >> N >> M;
    vector<vi> data(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        data[a].push_back(b);
        data[b].push_back(a);
    }
    vi per(N);
    for (int i = 0; i < N; i++) {
        per[i] = i + 1;
    }
    int ans = 0;
    do {
        if (per[0] != 1) {
            break;
        }
        bool check;
        for (int i = 0; i < N - 1; i++) {
            check = true;
            for (int x : data[per[i]]) {
                if (x == per[i + 1]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                break;
            }
        }
        if (!check) {
            ans++;
        }
    } while(next_permutation(per.begin(), per.end()));
    cout << ans << endl;
}
