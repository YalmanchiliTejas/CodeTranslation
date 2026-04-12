#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

#define MOD 1000000007
#define INF 2000000000

int GLL(LL& x) {
    return scanf("%lld", &x);
}

int GI(int& x) {
    return scanf("%d", &x);
}

int n;

vector<PII> x;

vector<int> res;

int main() {
    GI(n);

    x.resize(n);

    for (int i = 0; i < n; i++) {
        GI(x[i].FF);
        x[i].SS = i;
    }

    res.resize(n);

    sort(x.begin(), x.end());

    for (int i = 0; i < n/2; i++) {
        res[x[i].SS] = x[n/2].FF;
    }
    for (int i = n/2; i < n; i++) {
        res[x[i].SS] = x[n/2-1].FF;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", res[i]);
    }
    
    return 0;
}
