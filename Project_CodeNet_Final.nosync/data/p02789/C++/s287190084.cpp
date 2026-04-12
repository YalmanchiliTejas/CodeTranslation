#include <bits/stdc++.h>
using namespace std;

#define FST first
#define SCD second
#define MODP 1000000007

typedef long long LL;
typedef pair<int, int> PA;

int cmp(PA x, PA y) {
    return x.SCD < y.SCD;
}

int main() {
#ifdef FDB
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, k;
    cin>>n>>m;
    puts(n==m?"Yes":"No");
    return 0;
}