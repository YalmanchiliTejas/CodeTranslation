#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N = 505;
int S[N], T[N], n;
ll U[N], V[N], ans[N][N];
int t[N][N], R[N][2], C[N][2];
bool solve() {
    for(int k = 0; k < 64; k++) {
        memset(t, -1, sizeof t);
        memset(R, 0, sizeof R);
        memset(C, 0, sizeof C);
        for(int i = 1; i <= n; i++) {
            int x = (U[i] & 1);
            if(S[i] == x) continue;
            for(int j = 1; j <= n; j++) {
                if(~t[i][j] && t[i][j] != x) return false;
                t[i][j] = x;
            }
        }
        for(int i = 1; i <= n; i++) {
            int x = (V[i] & 1);
            if(T[i] == x) continue;
            for(int j = 1; j <= n; j++) {
                if(~t[j][i] && t[j][i] != x) return false;
                t[j][i] = x;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if((U[i] & 1) == (V[j] & 1)) t[i][j] = (U[i] & 1);
                if(t[i][j] == -1) t[i][j] = 0;
                R[i][t[i][j]]++;
                C[j][t[i][j]]++;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(S[i] && (U[i] & 1)) {
                if(R[i][1]) continue;
                for(int j = 1; j <= n; j++) {
                    if(!T[j] && !(V[j] & 1) && C[j][0] > 1) {
                        t[i][j] = 1;
                        R[i][0]--, C[j][0]--;
                        R[i][1]++, C[j][1]++;
                        break;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            if(T[i] && (V[i] & 1)) {
                if(C[i][1]) continue;
                for(int j = 1; j <= n; j++) {
                    if(!S[j] && !(U[j] & 1) && R[j][0] > 1) {
                        t[j][i] = 1;
                        R[j][0]--, C[i][0]--;
                        R[j][1]++, C[i][1]++;
                        break;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            if(S[i] == 0 && (U[i] & 1) == 1 && R[i][1] != n) return false;
            if(S[i] == 0 && (U[i] & 1) == 0 && R[i][1] == n) return false;
            if(S[i] == 1 && (U[i] & 1) == 1 && R[i][1] == 0) return false;
            if(S[i] == 1 && (U[i] & 1) == 0 && R[i][1] != 0) return false;
            if(T[i] == 0 && (V[i] & 1) == 1 && C[i][1] != n) return false;
            if(T[i] == 0 && (V[i] & 1) == 0 && C[i][1] == n) return false;
            if(T[i] == 1 && (V[i] & 1) == 1 && C[i][1] == 0) return false;
            if(T[i] == 1 && (V[i] & 1) == 0 && C[i][1] != 0) return false;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(t[i][j]) ans[i][j] |= (1ull << k);
            }
        }
        for(int i = 1; i <= n; i++) {
            U[i] >>= 1;
            V[i] >>= 1;
        }
    }
    return true;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &S[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &T[i]);
    for(int i = 1; i <= n; i++) scanf("%llu", &U[i]);
    for(int i = 1; i <= n; i++) scanf("%llu", &V[i]);
    if(!solve()) printf("-1\n");
    else {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                printf("%llu%c", ans[i][j], j == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}