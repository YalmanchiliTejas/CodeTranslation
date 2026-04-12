#include <cstdio>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int N = 2e5 + 500;
const int OFF = (1 << 18);

ll dp[N];
int n, l[N], r[N], a[N], m;
vector < pii > v[N];

ll tour[2 * OFF],prop[2 * OFF];

void update(int i,int a,int b,int lo,int hi, ll x){
    if(lo <= a && b <= hi){
        tour[i] += x;
        prop[i] += x;
        return;
    }
    if(a > hi || b < lo) return;
    update(2 * i, a, (a + b) / 2, lo, hi, x);
    update(2 * i + 1, (a + b + 2) / 2, b, lo, hi, x);
    tour[i] = max(tour[2 * i], tour[2 * i + 1]) + prop[i];
}


int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i<m;i++){
        scanf("%d%d%d", l + i, r + i, a + i);
        v[r[i] - 1].PB({l[i] - 1, a[i]});
    }
    for(int i = 0;i<n;i++){
        dp[i] = tour[1];
        update(1, 0, OFF - 1, i, i, dp[i]);
        for(int j = 0;j<v[i].size();j++){
            update(1, 0, OFF - 1, v[i][j].X, i, v[i][j].Y);
        }

    }
    printf("%lld\n", tour[1]);
}
