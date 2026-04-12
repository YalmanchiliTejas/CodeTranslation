#include<bits/stdc++.h>

//#include "rubo.h"
//#define mp make_pair
//#define pb push_back
#define in int
#define ll long long
#define vc vector
#define SQ(j) (j)*(j)
//#define x first
//#define y second

//#define ld long double
#define dbl  long double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout << endl;

typedef long double ld;

using namespace std;


const int N = 3000 + 5;

int n;
ll a[N];

ll getMax(int l, int r);

ll getMin(int l, int r);

ll ZERO = 534756135857345ll;
ll memoMin[N][N];
ll memoMax[N][N];

ll getMax(int l, int r) {
    if(memoMax[l][r] != ZERO) return memoMax[l][r];
    if (l == r) {
        return a[l];
    }

    return memoMax[l][r] = max(
            a[l] + getMin(l + 1, r),
            a[r] + getMin(l, r - 1)
    );
}

ll getMin(int l, int r) {
    if(memoMin[l][r] != ZERO) return memoMin[l][r];
    if (l == r) {
        return -a[l];
    }

    return memoMin[l][r] = min(
            -a[l] + getMax(l + 1, r),
            -a[r] + getMax(l, r - 1)
    );
}

int main() {
    loop(i, N) loop(j, N) {
            memoMax[i][j] = ZERO;
            memoMin[i][j] = ZERO;
        }

    cin >> n;
    loop(i, n) {
        cin >> a[i];
    }

    ll res = getMax(0, n - 1);
    cout << res << endl;

    return 0;
}
