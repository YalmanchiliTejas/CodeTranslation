#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;


template<typename T> void read(vector<T>& v) {
    for (T& x : v)
        scanf("%llu", &x);
}
int bit(ull mask, int k) {
    return (mask >> k) & 1;
}


const int N = 505;

int n;
ull a[N][N];
bool notset[N][N];
ull ans[N][N];
int sR[N], sC[N];
int bR[N], bC[N];
bool usedR[2], usedC[2];

bool solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 0;
            notset[i][j] = true;
        }
    }
    usedR[0] = usedR[1] = false;
    for (int i = 0; i < n; ++i) {
        if (sR[i] != bR[i]) {
            usedR[bR[i]] = true;
            for (int j = 0; j < n; ++j)
                notset[i][j] = false, a[i][j] = bR[i];
        }
    }
    usedC[0] = usedC[1] = false;
    for (int i = 0; i < n; ++i) {
        if (sC[i] != bC[i]) {
            usedC[bC[i]] = true;
            for (int j = 0; j < n; ++j) {
                if (!notset[j][i] && a[j][i] != bC[i])
                    return false;
                notset[j][i] = false, a[j][i] = bC[i];
            }
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

    vector<int> posR, posC;
    int okR = 0, okC = 0;
    for (int i = 0; i < n; ++i) {
        if (sR[i] == bR[i]) {
            if (usedC[bR[i]]) ++okR;
            posR.push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (sC[i] == bC[i]) {
            if (usedR[bC[i]]) ++okC;
            posC.push_back(i);
        }
    }

    /*
    printf("%d %d ", sz(posR), okR);
    printf("%d %d\n", sz(posC), okC);
    */

    if (sz(posC) == 0) {
        if (sz(posR) != okR)
            return false;
        return true;
    }
    if (sz(posR) == 0) {
        if (sz(posC) != okC)
            return false;
        return true;
    }
    if (sz(posC) == 1) {
        int cnt = 0;
        for (int i : posR) {
            if (usedC[bR[i]]) {
                a[i][posC[0]] = bC[posC[0]];
            } else {
                a[i][posC[0]] = bR[i];
            }
            cnt += (a[i][posC[0]] == bC[posC[0]]);
        }
        /*
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        */
        if (okC == 1 || cnt)
            return true;
        return false;
    }
    if (sz(posR) == 1) {
        int cnt = 0;
        //printf("%d\n", posR[0]);
        for (int i : posC) {
            if (usedR[bC[i]]) {
                //printf("hui %d %d\n", i, bR[posR[0]]);
                a[posR[0]][i] = bR[posR[0]];
            } else {
                a[posR[0]][i] = bC[i];
            }
            cnt += (a[posR[0]][i] == bR[posR[0]]);
        }
        /*
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        */
        if (okR == 1 || cnt)
            return true;
        return false;
    }

    for (int i = 0; i < sz(posR); ++i) {
        for (int j = 0; j < sz(posC); ++j)
            a[posR[i]][posC[j]] = (i + j) & 1;
    }
    return true;
}


const int LOG = 64;


int main()
{
    //freopen("input.txt", "r", stdin);


    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &sR[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &sC[i]);
    vector<ull> vR(n), vC(n);
    read(vR), read(vC);

    for (int b = 0; b < LOG; ++b) {
        for (int i = 0; i < n; ++i) {
            bR[i] = bit(vR[i], b);
            bC[i] = bit(vC[i], b);
        }
        //printf("\n\nbit %d:\n", b);
        if (!solve()) {
            printf("-1\n");
            return 0;
        }
        /*
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
        */
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 1) ans[i][j] |= (ull)1 << b;
            }
        }
    }

    //printf("ans:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%llu ", ans[i][j]);
        printf("\n");
    }

}
