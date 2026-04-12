#include <bits/stdc++.h>
using namespace std;

#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )

const int INF = 1e9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;


int main() {

    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    fo(i, h) cin >> grid[i];

    set<int> row, col;
    fo(i, h) {
        int cont = 0;
        fo(j, w) {
            if ( grid[i][j] == '.' ) cont++;
        }
        if ( cont == w ) row.insert(i);
    }

    fo(j, w) {
        int cont = 0;
        fo(i, h) {
            if ( grid[i][j] == '.' ) cont++;
        }
        if ( cont == h ) col.insert(j);
    }

    fo(i, h) {
        if ( row.find(i) != row.end() ) continue;
        fo(j, w) {
            if ( col.find(j) != col.end() ) continue;
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}