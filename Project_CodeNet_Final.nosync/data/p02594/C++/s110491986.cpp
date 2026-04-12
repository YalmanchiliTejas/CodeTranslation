#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef long double ld;
const double E = 1e-7;
const ll INF = 1e17;
#define forn(i, s, f) for (int i = s; i < f; ++i)
#define ft first                                                 
#define sec second
#define fora(i, n) for (auto i : n)
#define sz(a) (int)(a).size()
#define sort_(a) sort(a.begin(), a.end())
#define pb push_back
#define mp make_pair
#define rsort_(a) sort(a.begin(), a.end()); reverse(a.begin(), a.end())
#define fast_ cin.tie(0), ios_base::sync_with_stdio(false)
// ____________________________________________________________
#define cina(a) forn(i,0,sz(a)) cin >> a[i]
#define cinpr(a) cin >> a.ft >> a.sec 
//--------------------------------------------------------------
 
int main() {
    int n; cin >> n;
    if (n >= 30) cout << "Yes\n";
    else cout << "No\n";
}