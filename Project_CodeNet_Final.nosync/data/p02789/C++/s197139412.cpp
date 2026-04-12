    #include <vector>
    #include <string>
    #include <tuple>
    #include <iostream>
    #include <sstream>
    #include <algorithm>
    #include <set>
    #include <map>
    #include <cmath>
    #include <numeric>
    #include <queue>

    #define ll long long
    #define ld long double

    using namespace std;

    vector<ll> vert;

    ll getComp(ll v) {
        if(vert[v] == v) {
            return v;
        } else {
            return vert[v] = getComp(vert[v]);
        }
    }

    void edg(ll a, ll b) {
        a = getComp(a);
        b = getComp(b);
        vert[a] = b;
    }

    vector<vector<ll>> mat;

    ll dx[]{0, 1, 0, -1};
    ll dy[]{1, 0, -1, 0};

    bool isValid(ll x, ll y, ll n, ll m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int main() {
        ll n, m;cin >> n >> m;cout << ((n == m) ? "Yes" : "No");
    }
