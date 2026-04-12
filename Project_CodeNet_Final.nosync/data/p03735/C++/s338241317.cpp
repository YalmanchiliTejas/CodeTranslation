#include <bits/stdc++.h>
#define INF 1234567890ll
using namespace std;
typedef long long LL;
typedef pair<LL, int> pii;

int N;
int cnt[202020], K;
pii P[404040];
LL A[202020], B[202020];
LL ans;

int main(){
    scanf("%d", &N);
    LL Rmin=INF, Rmax=-INF, Bmin=INF, Bmax=-INF;
    for (int i=1; i<=N; i++){
        scanf("%lld %lld", &A[i], &B[i]);
        if (A[i] > B[i]) swap(A[i], B[i]);
        Rmin = min(Rmin, A[i]);
        Rmax = max(Rmax, A[i]);
        Bmin = min(Bmin, B[i]);
        Bmax = max(Bmax, B[i]);
        P[i] = pii(A[i], i);
        P[N+i] = pii(B[i], i);
    }
    ans = (Bmax - Bmin) * (Rmax - Rmin);
    sort(P+1, P+2*N+1);
    int t=0;
    for (int i=1; i<=2*N; i++){
        if (cnt[P[i-1].second] == 1) K--;
        cnt[P[i-1].second]--;
        while (t <= 2*N && K < N){
            t++;
            if (!cnt[P[t].second]) K++;
            cnt[P[t].second]++;
        }
        if (t > 2*N) break;
        ans = min(ans, (Bmax-Rmin) * (P[t].first - P[i].first));
    }
    printf("%lld\n", ans);
    return 0;
}
