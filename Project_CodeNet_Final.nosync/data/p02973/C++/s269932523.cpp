#pragma region include
#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 4e18;
void input() {}
template<typename... R> void input(int& f, R&... r) { scanf("%d", &f); input(r...); }
template<typename... R> void input(double& f, R&... r) { scanf("%lf", &f); input(r...); }
template<typename... R> void input(ll& f, R&... r) { scanf("%lld", &f); input(r...); }
template<typename... R> void input(char& f, R&... r) { scanf("%c", &f); input(r...); }
template<typename T, typename... R> void input(vector<T>& f, R&... r) { REP(i, f.size())input(f[i]); input(r...); }
#pragma endregion

// LIS　最長増加部分列(非減少)
int LIS(const vector<int> &A) {
    vector<int> lis(A.size(), INF);
    for (int i = 0; i < A.size(); i++)
    {
        lis[upper_bound(ALL(lis), A[i]) - lis.begin()] = A[i];
    }
    return lower_bound(ALL(lis), INF) - lis.begin();
}

int main() {
    int n; input(n);
    vector<int> a(n),b(n); input(a);
    REP(i, n) {
        b[n - 1 - i] = a[i];
    }
    cout << LIS(b) << endl;
    getchar(); getchar();
}