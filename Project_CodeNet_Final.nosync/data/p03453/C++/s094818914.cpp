#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

const long long N = 400100;
const long long MOD = 1000000007;

long long n, m, s, t;
long long a[N], b[N], d[N];
vector<pair<long long, long long> > v[N];
long long dm1[N], dm2[N], n1[N], n2[N];
set<pair<long long, long long> > q;

void calcd(long long s, long long *d, long long *nr) {
    q.insert(pair<long long, long long>(0, s));
    nr[s] = 1;

    while(!q.empty()) {
        long long dis = q.begin()->first, x = q.begin()->second;
        q.erase(q.begin());

        if(dis > d[x])
            continue;

        for(auto it : v[x]) {
            long long nd = dis + it.second, el = it.first;

            if(nd == d[el]) {
                nr[el] = (nr[el] + nr[x]) % MOD;
            }
            if(nd < d[el] || !nr[el]) {
                nr[el] = nr[x];
                d[el] = nd;

                q.insert(pair<long long, long long>(nd, el));
            }
        }
    }
}

long long check(long long a, long long b, long long d) {
    if(dm1[a] + dm2[b] + d != dm1[t])
        return 0;

    if(dm1[a] + d <= dm2[b])
        return 0;
    if(dm2[b] + d <= dm1[a])
        return 0;

    long long rr = (1LL * n1[a] * n2[b]) % MOD;
    rr = (1LL * rr * n1[a]) % MOD;
    rr = (1LL * rr * n2[b]) % MOD;

    return rr;
}

int main() {
    long long i;
    //freopen("ttt", "r", stdin);

    cin >> n >> m >> s >> t;
    for(i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i] >> d[i];
        v[a[i]].push_back(pair<long long, long long>(b[i], d[i]));
        v[b[i]].push_back(pair<long long, long long>(a[i], d[i]));
    }

    calcd(s, dm1, n1);
    calcd(t, dm2, n2);

    long long nrtot = (1LL * n1[t] * n1[t]) % MOD, nr = 0;

    //long longersetie noduri
    for(i = 1; i <= n; ++i) if(dm1[i] == dm2[i] && dm1[i] + dm2[i] == dm1[t]) {
        long long tt = (1LL * n1[i] * n2[i]) % MOD;
        tt = (tt * n1[i]) % MOD;
        tt = (tt * n2[i]) % MOD;
        nr = (1LL * nr + tt) % MOD;
    }

    //muchii
    for(i = 1; i <= m; ++i) {
        nr = (1LL * nr + check(a[i], b[i], d[i]) + check(b[i], a[i], d[i])) % MOD;
    }

    nrtot = (nrtot - nr + MOD) % MOD;
    cout << nrtot;

    return 0;
}
