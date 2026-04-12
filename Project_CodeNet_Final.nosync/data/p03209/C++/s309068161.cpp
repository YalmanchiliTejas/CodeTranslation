#include <bits/stdc++.h>
#define debug(x) cerr << "\n" \
                      << #x << ": " << x << "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define INF (1LL << 30)
#define int long long
#define pii pair<long long, long long>
#define MOD 1000000007
#define print(x) cout << (x) << endl
using namespace std;
typedef long long ll;

int mem[52][2]; // [0]: P, [1]: B
int layer[52];
int layersum[52];
int memsum[52][2];

void a()
{
    mem[0][0] = 1;
    mem[0][1] = 0;
    memsum[0][0] = 1;
    memsum[0][1] = 0;
    layer[0] = 1;
    
    layersum[0] = 1;
    FOR(i,1, 51)
    {
        mem[i][0] = mem[i - 1][0] * 2 + 1;
        mem[i][1] = mem[i - 1][1] * 2 + 2;
        memsum[i][0] = memsum[i-1][0] + mem[i][0];
        memsum[i][1] = memsum[i-1][1] + mem[i][1];
        layer[i] = mem[i][0] + mem[i][1];
        layersum[i] = layersum[i-1] + layer[i];
    }
}

signed main()
{
    int N,X;
    cin>>N>>X;
    a();
    int ans = 0;

    int l = 0;

    for(int i=N; i>=1; --i){
        if (X == 0) break;
        --X;

        if (X <= layer[i-1]) continue;
        ans += mem[i-1][0] +1;
        X -= layer[i-1] + 1;
    }
    if (X) ans++;

    cout<<ans<<endl;
    return 0;
}