#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define all(v) begin(v), end(v)
#define pb(a) push_back(a)
#define fr first
#define sc second
#define INF 2000000000
#define int long long int

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define LEQ(n, m) ((n) <= (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define GEQ(n, m) ((n) + EPS >= (m))

typedef vector<int> VI;
typedef vector<VI> MAT;
typedef pair<int, int> pii;
typedef long long ll;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
int const MOD = 1000000007;
ll mod_pow(ll x, ll n) {return (!n)?1:(mod_pow((x*x)%MOD,n/2)*((n&1)?x:1))%MOD;}
int madd(int a, int b) {return (a + b) % MOD;}
int msub(int a, int b) {return (a - b + MOD) % MOD;}
int mmul(int a, int b) {return (a * b) % MOD;}
int minv(int a) {return mod_pow(a, MOD-2);}
int mdiv(int a, int b) {return mmul(a, minv(b));}

namespace std {
    bool operator<(const P& a, const P& b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

// split??¢??° (1?????????????????§?????????????????????????????§??????????????????)
vector<string> split(string s, char c) {
    vector<string> ret;
    string temp;
    replace(s.begin(), s.end(), c, ' ');
    stringstream ss(s);
    while(ss >> temp) ret.pb(temp);
    return ret;
}

string s;
int res;
signed main() {
    cin >> s >> res;
    int a = 0, b = 0;
    // multiplication-first rule
    vector<string> cls = split(s, '+');
    rep(i,0,cls.size()) {
        int temp = 1;
        rep(j,0,cls[i].length()) {
            if(cls[i][j] != '*') temp *= (cls[i][j] - '0');
        }
        a += temp;
    }

    // left-to-right rule
    rep(i,0,s.length()) {
        if(i == 0) b += (s[i] - '0');
        else if(s[i] == '+') b += (s[i+1] - '0');
        else if(s[i] == '*') b *= (s[i+1] - '0');
    }

    if(res == a && res == b) cout << "U" << endl;
    if(res != a && res == b) cout << "L" << endl;
    if(res == a && res != b) cout << "M" << endl;
    if(res != a && res != b) cout << "I" << endl;
    return 0;
}