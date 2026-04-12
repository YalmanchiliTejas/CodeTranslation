#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        std::cin.tie(0);
        ios::sync_with_stdio(false);
        cout.precision(20);
    }
} fast;

/* define */
#define FOR(I, X, Y) for (long long(I) = (X); (I) < (Y); (I)++)
#define REP(I, X, Y) for (long long(I) = (Y)-1; (I) >= (X); (I)--)
#define ALL(X) (X).begin(), (X).end()
#define pb push_back
#define COUNT(V, X)                           \
    (upper_bound((V).begin(), (V).end(), X) - \
     lower_bound((V).begin(), (V).end(), X))
#define debug(x) cerr << #x << ':' << x << endl;
#define DEBUG(v)                             \
    {                                        \
        cerr << #v << ':';                   \
        for (auto xv : v) cerr << xv << ' '; \
        cerr << endl;                        \
    }
#define Yes(X) cout << (X ? "Yes" : "No") << endl;
#define YES(X) cout << (X ? "YES" : "NO") << endl;
#define ctoi(C) (C - '0')
#define pow2(x) ((long long)((long long)1 << x))

/* alias */
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using minPQ = priority_queue<T, vector<T>, greater<T>>;

/* const */
const long long dx[] = {1, 0, -1, 0};
const long long dy[] = {0, 1, 0, -1};
const long long dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
const long long dx9[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
const long long dy9[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
const int INF = 1000000007;
const long long LINF = 1000000000000000007;

/* func */
template <typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) {
    if (a > b) a = b;
    return a > b;
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) {
    if (a < b) a = b;
    return a < b;
}
long long max(long long x, int y) {
    return max(x, (long long)y);
}
long long max(int x, long long y) {
    return max((long long)x, y);
}
long long min(long long x, int y) {
    return min(x, (long long)y);
}
long long min(int x, long long y) {
    return min((long long)x, y);
}

/* library */

// https://www.geeksforgeeks.org/minimum-number-of-increasing-subsequences/

int MinimumNumIncreasingSubsequences(int arr[], int n) {
    multiset<int> last;

    // last element in each  increasing subsequence
    // found so far
    for (int i = 0; i < n; i++) {
        // here our current element is arr[i]
        multiset<int>::iterator it = last.lower_bound(arr[i]);

        // iterator to the first element larger
        // than or equal to arr[i]
        if (it == last.begin())

            // if all the elements in last larger
            // than or to arr[i] then insert it into last
            last.insert(arr[i]);

        else {
            it--;

            // the largest element smaller than arr[i] is the number
            // before *it which is it--
            last.erase(it);       // erase the largest element smaller than arr[i]
            last.insert(arr[i]);  // and replace it with arr[i]
        }
    }
    return last.size();  // our answer is the size of last
}

/* main */

signed main() {
    int N;
    cin >> N;
    int A[N];
    for (auto &x : A) cin >> x;
    cout << MinimumNumIncreasingSubsequences(A, N) << endl;
}