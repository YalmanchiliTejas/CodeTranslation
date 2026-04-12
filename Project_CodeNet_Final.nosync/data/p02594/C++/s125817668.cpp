#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <fstream>
#include <bitset>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef priority_queue<int> pqi;
typedef priority_queue<ii> pqii;
typedef map<int, int> mii;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef set<int> si;
typedef set<ll> sl;
typedef map<ll, ll> mll;
typedef queue<int> qi;
typedef queue<ii> qii;
typedef vector<string> vs;
typedef pair<ll, ll> iil;
typedef vector<iil> viil;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int, ii> iii;
typedef vector<pair<pair<int,int>,int>> viii;
typedef vector<pair<pair<ll,ll>,ll>> viiil;

#define pb push_back
#define mp make_pair
#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define INF 1000000000
#define MOD 1000000007;

void solve() {
    int x;
    cin >> x;
    if (x >= 30) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }
}

void querySolve() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //querySolve();
    solve();

}
