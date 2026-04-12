#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> ii;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vii;
typedef long double ld;
typedef vector<ld> vld;
typedef vector<vector<ld>> vvld;
typedef vector<bool> vbl;
typedef vector<vbl> mbl;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(s) (s).begin(), (s).end()
const ll MOD = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s;
    cin >> s;
    if (s.compare("BBB") == 0 || s.compare("AAA") == 0)
        cout << "No";
    else
    {
        cout << "Yes";
    }
    
    return 0;
}