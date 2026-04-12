#include <bits/stdc++.h>
using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define CALL(c) (c).cbegin(), (c).cend()
#define RALL(c) (c).rbegin(), (c).rend()
#define CRALL(c) (c).crbegin(), (c).crend()
#define REP(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define FOR(i, s, n) for (int i = s; i < static_cast<int>(n); i++)
#define PSORT(s,p,e) partial_sort((s), next((s), (p)), (e))
#define VIEW(v,t) for_each((v).begin(), (v).end(), [](t& a) { cout << a << " "; }); cout << endl;

const int INF = INT_MAX;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

using PII = pair<int, int>;
using LL = long long;
using ULL = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using V2 = vector<vector<T>>;
template<class T, int W=255> using A = array<T, W>;
template<class T, int W=255, int H=255> using A2 = array<array<T, W>, W>;

int n;
V<int> h;

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cin >> n;

    REP(i, n) {
        int a;
        cin >> a;
        h.push_back(a);
    }

    int ans = 1;
    int m = h[0];
    FOR(i, 1, h.size()) {
        if(m <= h[i]) ans++;
        m = max(m, h[i]);
    }
    cout << ans << "\n";
}