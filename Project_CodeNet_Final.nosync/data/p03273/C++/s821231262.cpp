#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    int h, w; cin >> h >> w;
    char a[101][101];
    REP(i, h) {
        REP(j, w) {
            cin >> a[i][j];
        }
    }
    set<char> white_row_idx;
    set<char> white_col_idx;
    REP(i, h) {
        bool is_white_row = true;
        REP(j, w) {
            if (a[i][j] != '.') {
                is_white_row = false;
            }
        }
        if (is_white_row) {
            white_row_idx.insert(i);
        }
    }
    REP(j, w) {
        bool is_white_col = true;
        REP(i, h) {
            if (a[i][j] != '.') {
                is_white_col = false;
            }
        }
        if (is_white_col) {
            white_col_idx.insert(j);
        }
    }
    REP(i, h) {
        if (white_row_idx.find(i) == white_row_idx.end()) {
            REP(j, w) {
                if (white_col_idx.find(j) == white_col_idx.end()) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}