#include <bits/stdc++.h>
#pragma comment(linker, "/stack:256000000")
#pragma gcc optimize("O3")
#pragma gcc target("sse4")
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;
typedef pair<ll, ll> pll;
typedef string str;
typedef vector<int> vi;
typedef vector<ll> vll;
//#define HASH
#define pb push_back
#define forn(i, n) for(ll (i) = 0; (i) < (n); ++(i))
#define fornm(i, m, n) for(ll (i) = (m); (i) < (n); ++(i))
#define rfornm(i, m, n) for(ll (i) = (m); (i) >= (n); --(i))
#define fin() for(ll i = 0; i < n; ++i)
#define readvec(vector, n) {ll temp_vec_val;forn(i, n){cin >> temp_vec_val;vector.push_back(temp_vec_val);}}
#define printvec(vector, delimeter) {ll length_of_vector=vector.size();\
                                    forn(i, length_of_vector){cout << vector[i] << delimeter;}}
#define sortvec(vector) sort(vector.begin(), vector.end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    ll x, y, z;
    cin >> x >> y >> z;
    ll c = 0;
    x -= z;
    while (x >= y+z) {
        c++;
        x -= (y+z);
    }
    cout << c << endl;
    return 0;
}
