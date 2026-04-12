#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
template <typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
#define forn(i,n) for(int i=0; i<int(n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

void no() {
    cout << "Impossible\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vs grid(H);
    for (string& row:grid) cin >> row;
    int i=0, j=0;
    for (; i+1<H || j+1<W;) {
        if (grid[i][j]!='#') no();
        bool down=(i+1<H && grid[i+1][j]=='#');
        bool right=(j+1<W && grid[i][j+1]=='#');
        if (down==right) no();
        grid[i][j]='.';
        i+=down;
        j+=right;
    }
    grid[i][j]='.';
    for (string& row:grid) for (char c:row)
        if (c!='.') no();
    cout << "Possible\n";
}
