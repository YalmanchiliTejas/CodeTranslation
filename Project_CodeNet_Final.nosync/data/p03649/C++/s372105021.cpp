#include <bits/stdc++.h>

#define LL long long
#define VI vector<int>
#define VB vector<bool>
#define VL vector<long long>
#define FOR(i,a,b) for(int i= (a); i<((int)b); ++i)
#define RFOR(i,a) for(int i=(a); i >= 0; --i)
#define FOE(i,a) for(auto i : a)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v,x) (std::find(v.begin(), v.end(), x) != v.end())
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define EPS 1e-14

const std::string YES = "YES";
const std::string Yes = "Yes";
const std::string NO = "NO";
const std::string No = "No";

using namespace std;


int solve(LL N, vector<LL> &A) {
    LL ans = 0;
    sort(RALL(A));

    bool change = true;
    while (change) {
        change = false;
        FOR(i, 0, A.size()) {
            LL n = A[i] / N;
            A[i] -= (n * N);
            FOR(j, 0, A.size()) {
                if (i != j) {
                    A[j] += n;
                }
            }
            ans += n;
            change |= (n >= 1);
        }
    }

    cout << ans << endl;

}


int main() {
    LL N;
    cin >> N;
    vector<LL> A(N);
    FOR(i, 0, N) {
        cin >> A[i];
    }
    solve(N, A);

    return 0;
}