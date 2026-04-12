
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define PI 3.1415926535897932384626
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define Rep(i, a, b) for (int i=a; i<(b); i++)
#define rep(i, a) for (int i=0; i<(a); i++)
#define Dep(i,a,b) for (int i = (b)-1; i >= a; i--)
#define dep(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for(auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // Random No.

const int MOD = 1000000007;
const char nl = '\n';

void sol() {

    int n ; cin >> n;

    if (n >= 30) {cout << "Yes\n";}
    else {cout <<  "No\n";}

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("outputA.txt", "w", stdout);
#endif

    int T = 1;
    while (T--) {
        sol();
    }

    return 0;
}

