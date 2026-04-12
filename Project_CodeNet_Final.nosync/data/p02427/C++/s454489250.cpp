#include<bits/stdc++.h>

using namespace std;


#define int long long
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)


using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

#define SIZE 19

int N;
int POW[SIZE];

signed main() {
    POW[0] = 1;
    for (int i = 1; i < SIZE; i++) {

        POW[i] = POW[i - 1] * 2;
    }

    scanf("%d", &N);

    printf("0:\n");
    int index = 1;

    for (int state = 1; state < POW[N]; state++) {
        printf("%d:", index++);
        for (int loop = 0; loop < N; loop++) {
            if (state & (1 << loop)) {
                printf(" %d", loop);
            }
        }
        printf("\n");
    }

    return 0;
}
