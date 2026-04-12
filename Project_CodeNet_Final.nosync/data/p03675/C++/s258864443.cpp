#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long 
#define ld long double
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
 
#define y1 what

using namespace std;

const int N = (int) 2e5 + 10;
const int M = (int) 2e6 + 10;
const ll LINF = (ll) 1e18;
const int INF = (int) 1e9 + 7;
const double EPS = (double) 1e-9;
const double PI =  3.14159265359;

int n;
int a[N], b[N];   

int main() {
    #define fn "bst"
    #ifdef witch
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        //freopen(fn".in", "r", stdin);
        //freopen(fn".out", "w", stdout);
    #endif
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n;
    for (int i = n; i >= 1; i--) {
        if ((n - i) % 2 == 0) {
            b[l] = a[i];
            l++;
        } else {
            b[r] = a[i];
            r--;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}