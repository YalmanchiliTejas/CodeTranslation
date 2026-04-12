#include <bits/stdc++.h>

using namespace std;

int n, k, b, q;
long long res;

int main() {

    scanf("%d%d",&n,&k);
    for (b=k+1;b<=n;b++)for (q=0;b*q<=n;q++) res += max(min(n-b*q,b-1)-max(k,1-b*q)+1,0);
    printf("%lld\n",res);

    return 0;
}
