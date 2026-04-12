#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

int a[200000];
map<int, ll> m[200004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = gi();
    for (int i = 0; i < n; i++)
        a[i] = gi();

    m[0][0] = 0;
    m[1][0] = 0;
    m[1][1] = a[0];
    for (int i = 2; i <= n; i++) {
        int mx = (i+1)/2;
        int mn = n/2 - (n-i+1)/2;
        for (int h = mn; h <= mx; h++) {
            ll c = a[i-1] + m[i-2][h-1];
            if (m[i-1].find(h) != m[i-1].end()) {
                ll d = m[i-1][h];
                c = MAX(c, d);
            }
            m[i][h] = c;
        }
    }

    cout << m[n][n/2] << endl;

    return 0;
}
