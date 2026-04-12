#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX*/

using namespace std;

using ll = long long;

#define mp make_pair

const int p = 1000000007;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}

/*struct DSU {
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};*/

const int N = 1000000;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}

const int M = 1005;

vector<vector<int>> dp(M, vector<int>(M));


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    init();

    int n, a, b, c, d;
    cin>>n>>a>>b>>c>>d;

    for (int i = 0; i<=n; i++)
        for (int j = a; j<=b; j++)
        {
            if (j==a)
            {
                if (i%a!=0) dp[i][j] = 0;
                else if ((i/a)!=0 && ((i/a)<c || (i/a)>d)) dp[i][j] = 0;
                else dp[i][j] = mul(mul(facs[i], invfacs[i/j]), po(invfacs[j], i/j));
                continue;
            }
            dp[i][j] = add(dp[i][j], dp[i][j-1]);
            for (int k = c; k<=min(d, i/j); k++)
            {
                dp[i][j] = add(dp[i][j], mul(dp[i-j*k][j-1], mul(C(i, j*k), mul(mul(facs[j*k], invfacs[k]), po(invfacs[j], k)))));
            }
        }
    /*for (int i = 0; i<=n; i++)
        for (int j = a; j<=b; j++)
        {
            cout<<i<<' '<<j<<": "<<dp[i][j]<<endl;
        }*/

    cout<<dp[n][b];
}