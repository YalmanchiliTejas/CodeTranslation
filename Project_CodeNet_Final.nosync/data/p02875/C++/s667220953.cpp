#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e7+7, M = 998244353;
LL fac[N], invfac[N];
LL p2[N], p3[N];

LL power(LL a, LL p) {
    if (p==0)   return 1;
    LL ans = power(a, p/2);
    ans = (ans * ans)%M;
    if (p%2)    ans = (ans * a)%M;
    return ans;
}

LL pre() {
    fac[0] = 1;
    for (int i=1; i<N; i++) fac[i] = (fac[i-1]*i)%M;
    invfac[N-1]=  power(fac[N-1], M-2);
    for (int i=N-2; i>=0; i--)  invfac[i] = (invfac[i+1]*(i+1))%M;

    p2[0] = p3[0] = 1;
    for (int i=1; i<N; i++) {
        p2[i] = (p2[i-1]*2)%M;
        p3[i] = (p3[i-1]*3)%M;
    }
}

LL C(int n, int r) {
    if (r < 0 || r > n) return 0;
    LL num = fac[n];
    LL den = (invfac[r]*invfac[n-r])%M;
    return (num*den)%M;
}

LL f[N];
LL suf[N];

int main() {
    pre();
    int n;
    cin>>n;
    int m = n/2;

    for (int i=0; i<=m; i++)    {
        f[i] = (C(m, i)*p2[m-i])%M;
    }

    for (int i=m; i>=0; i--) {
        suf[i] = (suf[i+1] + f[i])%M;
    }

    LL ans =- 0;

    for (int i=0; i<=m; i++)    {
        ans = (ans + f[i] * suf[m-i+1])%M;
    }
    ans = (ans * 2)%M;
    ans = (p3[2*m] - ans + M)%M;
    cout<<ans<<endl;
}