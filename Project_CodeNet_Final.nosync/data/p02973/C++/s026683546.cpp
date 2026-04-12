#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define whole(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
 
const int N = int(2e5) + 2;
const int LG = 20;
const ll mod = (int)1e9 + 7;
const int INF = (int)1e9 + 7;
const ll linf = 1e18; 
const ld pi = acos(-1);
const int base = 10;
const ld EPS = 1e-9;

int n, a[N];
int main (){
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) scanf ("%d", a + i);
    multiset < int > res;
    for (int i = 1; i <= n; ++i){
        auto to = res.lower_bound(a[i]);
        if (to == res.begin()) res.insert(a[i]);
        else {
            to--;
            res.erase(to);
            res.insert(a[i]);
        }
    }
    printf ("%d\n", sz(res));
}