#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

#define PB push_back
#define ALL(v) (v).begin(), (v).end()
#define SZ size()
#define FOR(i, a, n) for(long long (i) = (a); (i) < (n); (i)++)
#define REP(i, n) FOR((i), 0, (n))
#define SHOW(v) cout << (v) << endl
#define SHOW2(a, b) cout << (a) << " " << (b) << endl
#define SHOW3(a, b, c) cout << (a) << " " << (b) << " " << (c) << endl
#define GET(v) cin >> (v)
#define GET2(a, b) cin >> (a) >> (b)
#define GET3(a, b, c) cin >> (a) >> (b) >> (c)
#define MOD 1000000007
template<class T> void GETV(T &v) { REP(i, v.size()) { GET(v[i]); } }
template<class T> void SHOWV(T &v) { REP(i, v.size()) { SHOW(v[i]); } }

typedef long long ll;

int main()
{
    int x;
    GET(x);
    
    if(x == 5 || x == 3 || x == 7) {
        SHOW("YES");
    }
    else {
        SHOW("NO");
    }
    
    return 0;
}
