#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <math.h>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
const int mod = 998244353;
const double eps = 1e-8;

LL n, k;
LL len[55], p[55];

LL f(LL ce, LL k) {
    // B + f(ce - 1) + P + f(ce - 1) + B
    if(k == 1) {
        if(ce == 0) return 1;
        else return 0;
    }
    LL ans = 0;
    if(k >= len[ce - 1] + 1) {
        ans = p[ce - 1];
        k -= len[ce - 1] + 1;
        if(k > 0) {
            k --; ans ++;
        }
        if(k >= len[ce - 1]) {
            ans += p[ce - 1];
        } else if (k > 0){
            ans += f(ce - 1, k);
        }
    } else if (k > 1) {
        ans = f(ce - 1, k - 1);
    }
    return ans;
}

int main()
{
    len[0] = p[0] = 1;
    for(int i=1;i<=50;i++) {
        len[i] = len[i - 1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }
    cin>>n>>k;
    printf("%lld", f(n, k));
    return 0;
}