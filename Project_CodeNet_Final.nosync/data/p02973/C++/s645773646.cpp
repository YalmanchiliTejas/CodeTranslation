#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second
using namespace std;

const int N = 1e5+5;
int n, m, b[N], a, j;

int main()
{
    //freopen("a.inp","r",stdin);

    cin >> n;
    for(int i=1; i<=n; ++i) {
        scanf("%d",&a); a = -a;
        j = upper_bound(b+1, b+1+m, a) - b;
        m = max(m, j); b[j] = a;
    }
    cout << m;
}
