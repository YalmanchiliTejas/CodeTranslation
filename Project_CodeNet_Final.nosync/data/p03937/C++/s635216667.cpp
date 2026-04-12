#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> A(H+2);
    REP(i,1,H+1) {
        cin >> A[i];
        A[i] = "." + A[i] + ".";
    }
    REP(i,0,W+1) {
        A[0] += ".";
        A[H+1] += ".";
    }

    ll i = 1, j = 1;
    bool f = true;
    ll d = 0;
    while(i < H+1 && j < W+1) {
        if(d == 0 && A[i][j-1] == '#') {
            f = false;
            break;
        }
        else if(d == 1 && A[i-1][j] == '#') {
            f = false;
            break;
        }
        else {
            if(i == H && j == W) break;
            if(A[i+1][j] == '#' && A[i][j+1] == '.') {
                ++i;
                d = 0;
            }
            else if(A[i+1][j] == '.' && A[i][j+1] == '#') {
                ++j;
                d = 1;
            }
            else {
                f = false;
                break;
            }
        }
    }
    if(f) PR("Possible");
    else PR("Impossible");

    return 0;
}

/*

*/