#include <bits/stdc++.h>
using namespace std;

#define DUMP(x) cerr << #x << "=" << x << endl
#define DUMP2(x, y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")"<< endl
#define BINARY(x) static_cast<bitset<16> >(x)

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)

#define in_range(x, y, w, h) (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;
const int INF   = 1e9;
const ll  INFLL = 1e18;
typedef pair<int, int> PII;
int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};

int main()
{
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll ans = 0;
    bool update = true;

    while (update) {
        update = false;
        rep(i, N) {
            if (A[i] >= N) {
                update = true;
                ll need = ((A[i] - (N - 1)) + N - 1) / N;
                A[i] -= need * N;
                rep(j, N) if (i != j) A[j] += need;
                ans += need;
            }
        }
    }
    cout << ans << endl;
}