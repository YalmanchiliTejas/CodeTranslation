#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long int;

ll A[5010];
bool used[5010][5010];
int main() {
    int N; scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%lld", &A[i]);
    }

    sort(A, A+N);
    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if(used[i][j]) continue;
            used[i][j] = true;
            ll diff = A[j] - A[i]; int tmp = 2, pre = j;
            for(ll k=A[j]+diff; ; k+=diff) {
                int itr = lower_bound(A, A+N, k) - A;
                if(itr == N or A[itr] != k) break;
                tmp++;
                used[pre][itr] = true;
                pre = itr;
            }
            ans = max(ans, tmp);
        }
    }
    printf("%d\n", ans);
    return 0;
}

