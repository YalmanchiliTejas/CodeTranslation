#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i ,a, b) for (int i = a ; i <= b ; i++)
#define sz(a) int(a.size())
#define cuti(a) cout << a << endl;
#define cutii(a,b) cout << a << " " << b << endl;
#define cutiii(a,b,c) cout << a << " " << b << " " << c << endl;
#define vec(a) vector<int > a;

template<typename T,typename U> inline void chmin(T &x,U y){ if(y<x) x = y; }

typedef long long LL;
typedef pair<int ,int > pii;
typedef pair<string ,int > psi;
typedef pair<string ,string > pss;
typedef pair<LL, LL> pLL;

const long long oo = 1e9 + 7;
const double PI = acos(-1.0);

double DEG_to_RAD(double d) { return d * PI / 180.0; }

int X,Y,Z;
int ans;

int main(){
  // freopen("test.txt","r",stdin);
    cin >> X >> Y >> Z;
    ans++;
    X -= Y;
    X -= 2*Z;
    if ( X < 0) {
        cout << 0 << endl;
        return 0;
    }
    int tmp = Y + Z;
    ans += X / tmp;
    cout << ans << endl;
}
