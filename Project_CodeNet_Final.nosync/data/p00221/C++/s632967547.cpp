#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
#define FOR(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define eFOR(i,a,n) for(int (i)=(a);(i)<=(n);(i)++)
#define rFOR(i,a,n) for(int (i)=(n)-1;(i)>=(a);(i)--)
#define erFOR(i,a,n) for(int (i)=(n);(i)>=(a);(i)--)
#define SORT(i) sort((i).begin(),(i).end())
#define rSORT(i,a) sort((i).begin(),(i).end(),(a))
#define all(i) (i).begin(),(i).end()
constexpr ll INF = 1000000000;
constexpr ll LLINF = 1LL << 60;
constexpr ll mod = 1000000007;
constexpr ll MOD = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; }return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; }return 0; }
inline void init() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }
template<class T> inline istream& operator>>(istream& input, vector<T>& v) { for (auto& elemnt : v)input >> elemnt; return input; }

int main() {
    init();
    
    while (1) {
        int m, n;
        cin >> m >> n;
        if (!(m || n))break;

        int now = 0;
        vector<bool> alive(m, true);
        int a_cnt = m;
        eFOR(i, 1, n) {
            string ans = to_string(i);
            if (i % 15 == 0)ans = "FizzBuzz";
            else if (i % 5 == 0)ans = "Buzz";
            else if (i % 3 == 0)ans = "Fizz";

            while (!alive[now])(++now) %= m;

            string in;
            cin >> in;
            if (a_cnt == 1)continue;
            if (in != ans) {
                alive[now] = false;
                a_cnt--;
            }
            (++now) %= m;
        }

        VI ret(m);
        int k = 0;
        FOR(i, 0, m)if (alive[i]) {
            ret[k++] = i + 1;
        }
        ret.resize(k);
        FOR(i, 0, k)cout << ret[i] << (i == k - 1 ? "\n" : " ");
    }
    
}
