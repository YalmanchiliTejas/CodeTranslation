#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100000

int T[4 * MAXN];
int a[MAXN],b[MAXN];

int solve(int id, int l, int r, int x){
    if(r < x) return 0;
    if(l >= x) return T[id];
    int mi = (l + r) >> 1;
    return max(solve(2 * id + 1, l, mi, x), solve(2 * id + 2, mi + 1, r, x));
}

void update(int id, int l, int r, int x, int val){
    if(l > x || r < x) return;
    if(l == r) T[id] = val;
    else{
        int mi = (l + r) >> 1;
        update(2 * id + 1, l, mi, x, val);
        update(2 * id + 2, mi + 1, r, x, val);
        T[id] = max(T[2 * id + 1], T[2 * id + 2]);
    }
}

int main(){
    int N;

    scanf("%d",&N);

    for(int i = 0;i < N;++i){
        scanf("%d",&a[i]);
        b[i] = a[i];
    }

    sort(b, b + N);
    
    for(int i = 0;i < N;++i){
        int cur = a[i];
        int lo = 0,hi = N - 1,mi;

        while(lo < hi){
            mi = (lo + hi) / 2;

            if(b[mi] < cur) lo = mi + 1;
            else hi = mi;
        }

        a[i] = lo;
    }
    
    int ans = 0;

    for(int i = 0;i < N;++i){
        int best = solve(0, 0, N - 1, a[i]);
        //int best=0;
        update(0, 0, N - 1, a[i], best + 1);
        ans = max(ans, best + 1);
    }

    printf("%d\n", ans);

    return 0;
}
