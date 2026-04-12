#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

#define LL unsigned long long

const int N = 505;

int n;
int S[N], T[N];
LL U[N], V[N];
LL A[N][N];
int cntBitsCol[N][100];
int cntBitsRow[N][100];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &S[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &T[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%llu", &U[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%llu", &V[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        if (S[i] == 0) {
            for (int j = 1; j <= n; j++) {
                A[i][j] |= U[i];
            }
        }
        if (T[i] == 0) {
            for (int j = 1; j <= n; j++) {
                A[j][i] |= V[i];
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 64; k++) { 
                if (A[i][j] & (1ULL << k)) {
                    cntBitsRow[i][k]++;
                    cntBitsCol[j][k]++;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (S[i] == 1) {
            LL rowOr = A[i][1];
            for (int j = 1; j <= n; j++) {
                rowOr |= A[i][j];
            }
            if ((rowOr & U[i]) != rowOr) {
                printf("-1\n");
                return 0;
            }
            LL remaining = rowOr ^ U[i];
            for (int k = 0; k < 64; k++) {
                if (!(remaining & (1ULL << k))) {
                    continue;
                }
                bool found = false;
                for (int j = 1; j <= n; j++) {
                    if ((T[j] == 1 && ((1ULL << k) & V[j])) || (T[j] == 0 && cntBitsCol[j][k] < n - 1)) {
                        A[i][j] |= (1ULL << k);
                        cntBitsCol[j][k]++;
                        cntBitsRow[i][k]++;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
        if (T[i] == 1) {
            LL colOr = A[1][i];
            for (int j = 1; j <= n; j++) {
                colOr |= A[j][i];
            }
            if ((colOr & V[i]) != colOr) {
                printf("-1\n");
                return 0;
            }
            LL remaining = colOr ^ V[i];
            for (int k = 0; k < 64; k++) {
                if (!(remaining & (1ULL << k))) {
                    continue;
                }
                bool found = false;
                for (int j = 1; j <= n; j++) {
                    if ((S[j] == 1 && ((1ULL << k) & U[j])) || (S[j] == 0 && cntBitsRow[j][k] < n - 1)) {
                        A[j][i] |= (1ULL << k);
                        cntBitsRow[j][k]++;
                        cntBitsCol[i][k]++;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    printf("-1\n");
                    return 0;
                }
            }
            
        }
    }
    
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             printf("%llu ", A[i][j]);
//         }
//         printf("\n");
//     }
    
    for (int i = 1; i <= n; i++) {
        if (S[i] == 0) {
            LL rowAnd = A[i][1];
            for (int j = 1; j <= n; j++) {
                rowAnd &= A[i][j];
            }
            if (rowAnd != U[i]) {
                printf("-1\n");
                return 0;
            }
        } else {
            LL rowOr = A[i][1];
            for (int j = 1; j <= n; j++) {
                rowOr |= A[i][j];
            }
            if (rowOr != U[i]) {
                printf("-1\n");
                return 0;
            }
        }
        
        if (T[i] == 0) {
            LL colAnd = A[1][i];
            for (int j = 1; j <= n; j++) {
                colAnd &= A[j][i];
            }
            if (colAnd != V[i]) {
                printf("-1\n");
                return 0;
            }
        } else {
            LL colOr = A[1][i];
            for (int j = 1; j <= n; j++) {
                colOr |= A[j][i];
            }
            if (colOr != V[i]) {
                printf("-1\n");
                return 0;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%llu ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
