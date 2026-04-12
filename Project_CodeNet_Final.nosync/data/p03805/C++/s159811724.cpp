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
const int INF = 1e9;
typedef pair<int, int> PII;
int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};

int main()
{
    ios::sync_with_stdio(false);

    bool edge[10][10] = {};
    int N, M;
    cin >> N >> M;

    rep(i, M) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        edge[A][B] = edge[B][A] = true;
    }

    vector<int> vs(N);
    iota(ALL(vs), 0);

    int ans = 0;
    do {
        bool ok = true;
        rep(i, N-1) ok &= edge[vs[i]][vs[i+1]];
        ans += ok;
    } while (next_permutation(vs.begin()+1, vs.end()));
    cout << ans << endl;
}

