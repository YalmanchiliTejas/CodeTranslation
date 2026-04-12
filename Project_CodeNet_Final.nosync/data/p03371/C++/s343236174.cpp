#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PA;
typedef priority_queue<int, vector<int>, greater<int> > GQint;
typedef priority_queue<int> PQint;
typedef priority_queue<PA, vector<PA>, greater<PA> > GQpair;
typedef priority_queue<PA> PQpair;
typedef	set<int> Sint;
typedef	set<PA> SPA;
typedef map<int, int> MAP;
#define REP(i, a, n) for(ll i = (ll) a;i < (ll) n;i++)
#define fi first
#define se second
#define pb push_back
#define INF 5000000002
#define MOD 100000
#define MAXN 102
#define MAXM 1002
#define MAXK 100002

ll a, b, c, x, y, mi = INF, sa;

int main()
{
    cin >> a >> b >> c >> x >> y;
    sa = abs(x - y);
    mi = mi < (a * x + b * y) ? mi : (a * x + b * y);
    if(x > y){
        mi = mi < (y * 2 * c + a * sa) ? mi : (y * 2 * c + a * sa);
        mi = mi < (x * 2 * c) ? mi : (x * 2 * c);
    }
    else if(x < y){
        mi = mi < (x * 2 * c + b * sa) ? mi : (x* 2 * c + b * sa);
        mi = mi < (y * 2 * c) ? mi : (y * 2 * c);
    }
    else{
        mi = mi < (y * 2 * c) ? mi : (y * 2 * c);
        mi = mi < (x * 2 * c) ? mi : (x * 2 * c);
    }
    cout << mi << endl;

    return 0;
}
/*













*/
