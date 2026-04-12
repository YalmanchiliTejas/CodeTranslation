#include <bits/stdc++.h>

// limit
#define mod1 22439423LL
#define mod2 42342432LL
#define mod3 56454765LL
#define mod4 66867574LL
#define oo 1000000007LL
#define OO 1000000000000000007LL
#define maxN 17

// loop
#define fto(i, x, y) for(int i = (x); i <= (y); ++i)
#define fdto(i, x, y) for(int i = (x); i >= (y); --i)
#define ftoa(i, x, y, a) for(int i = (x); i <= (y); i += a)
#define fdtoa(i, x, y, a) for(int i = (x); i >= (y); i -= a)
#define ftosqrt(i, x, y) for(int i = (x); i*i <= (y); ++i)
#define ftoit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define fdtoit(rit, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)

// debug
#define debug cout << "*" << endl;
#define bug1d(a, x, y) { cout << #a << ": "; fto(_, x, y) cout << a[_] << ' '; cout << endl; }
#define bug2d(a, x, y, u, v) { cout << #a << ": " << endl; fto(i, x, y) {fto(j, u, v) cout << a[i][j] << ' '; cout << endl;}; cout << endl;}
#define bug(a) cout << #a << " = " << a << endl;
#define bug2(a, b) cout << #a << " = " << a << "; "; cout << #b << " = " << b << endl;
#define bug3(a, b, c) cout << #a << " = " << a << "; "; cout << #b << " = " << b << "; "; cout << #c << " = " << c << endl;

// operation
#define mp make_pair
#define pb push_back
#define pf push_front
#define mt make_tuple

// structure
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define matrix vector<vi>
#define iii pair <ii, int>

// get value
#define FF first
#define SS second
#define get(x, a) get<(x)>(a)

// data type
#define ll long long
#define ull unsigned long long

// function
#define lb lower_bound
#define ub upper_bound

// const value
#define pi 3.14159265358979323846264338327950288419716939937510

using namespace std;

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T min(T a, T b, T c, T d) {
    return min(a, min(b, min(c, d)));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
T max(T a, T b, T c, T d) {
    return max(a, max(b, max(c, d)));
}

bool cmp(const int& a, const int& b) {return a > b;}

bool check[107][107];

int main() {
//    #ifndef ONLINE_JUDGE
//        freopen("tmp.inp", "r", stdin);
//        freopen("tmp.out", "w", stdout);
//    #endif // ONLINE_JUDGE

    int n, m;
    scanf("%d%d", &n, &m);

    fto (i, 1, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        check[x][y] = check[y][x] = 1;
    }

    vi vc;
    fto (i, 2, n) vc.pb(i);

    int cnt = 0;
    do {
        int res = 1;
        int cur = 1;
        fto (i, 0, n-2) {
            if (!check[cur][vc[i]]) {
                res = 0;
                break;
            }
            cur = vc[i];
        }
        cnt += res;
    }
    while (next_permutation(vc.begin(), vc.end()));

    printf("%d\n", cnt);

    return 0;
}
