#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define EACH(e,v) for(auto& e:v)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort((v).rbegin(),(v).rend())
#define PERM(v) SORT(v);for(bool c##p=1;c##p;c##p=next_permutation(ALL(v)))
#define UNIQUE(v) SORT(v);(v).erase(unique(ALL(v)),(v).end())
template<typename A,typename B> inline bool chmax(A &a,const B &b){if(a<b){a=b;return 1;}return 0;}
template<typename A,typename B> inline bool chmin(A &a,const B &b){if(a>b){a=b;return 1;}return 0;}

const int MOD = (int)1e9 + 7;
const int INF = 1 << 30;
const ll INFF = 1LL << 62;

int N;
ll res = -INFF;
vector<int> S;

bool valid(int A, int B) {
    if (A <= 0 || B <= 0) return false;
    if (A <= B) return false;
    int g = __gcd(A, B);
    // A,BをGCDで割ったとき, 差が1じゃないなら大丈夫 (実験したらわかる)
    if (A / g - B / g != 1) return true;
    // mx : 例えば(3,2)のとき, (0,2,4,1,3,5)の順に訪れて, 次はもうどこにも行けない -> ハスが6個以下なら大丈夫
    //      一般化すると, (A,A-1)のとき, ハスが2*A個以下なら大丈夫
    int mx = (A / g + B / g + 1) * g;
    return (N <= mx);
}

signed main() {

    cin >> N;

    S.resize(N);
    REP(i, N) cin >> S[i];

    // d個飛ばしの累積和 : 調和級数でNlogN
    FOR(d, 1, N) {
        vector<ll> acc_front(1, 0), acc_back(1, 0);
        for (int i = d, j = 0; i < N; i += d)
            acc_front.emplace_back(acc_front[j++] + S[i]);
        for (int i = N - 1 - d, j = 0; i >= 0; i -= d)
            acc_back.emplace_back(acc_back[j++] + S[i]);
        int sz = acc_front.size();
        // 累積和からそれぞれ何個取り出すか
        REP(i, sz) {
            int A = N - 1 - d * i;
            int B = A - d;
            if (not valid(A, B)) continue;
            chmax(res, acc_front[i] + acc_back[i]);
        }
    }

    cout << res << endl;

}
