#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <iomanip>


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define rep(i, a, b) for (int i=a; i<(b); i++)
#define rp(i, a) for (int i=0; i<(a); i++)
#define repd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define rpd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define shandom_ruffle random_shuffle

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << std::setprecision(9);
    cout << std::fixed;

    char c;
    cin >> c;
    if(c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
        cout << "vowel";
    else
        cout <<"consonant";
    cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by super1 derived from bqi343
