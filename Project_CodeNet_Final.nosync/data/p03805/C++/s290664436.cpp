#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <cstdlib>
#define rep(i,x) for(int i=0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
using ld = long double;
using ll = long long;
const ll INF = 10010010010;
typedef pair<ll, ll> P;
const ll mod = 1000000007;
ll gcd(ll a, ll b) {//a>b
    if (a < b)swap(a, b);
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> path(N);
    vector<vector<ll>> num(M, vector<ll>(2));
    rep(i, M)cin >> num[i][0] >> num[i][1];
    rep(i, N)path[i] = i + 1;
    ll cnt = 0;
    do {
        bool ans = true;
        for (int i = 0; i < N - 1; i++) {
            bool yes = false;
            for (int j = 0; j < M; j++) {
                if (path[i] == num[j][0] && path[i + 1] == num[j][1])yes = true;
                if (path[i] == num[j][1] && path[i + 1] == num[j][0])yes = true;
            }
            if (!(yes))ans = false;
        }
        if (ans)cnt++;
    } while (next_permutation(path.begin() + 1, path.end()));
    cout << cnt << endl;
}