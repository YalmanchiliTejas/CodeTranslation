#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
#define ALL(x) x.begin(), x.end()
#define INF (1001000000)
#define SZ(a) int((a).size())
#define EACH(i,c) for(auto i:c)
#define EXIST(cs,v) (find(ALL(cs),(v))!=cs.end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define UNIQ(c) (c).erase(unique((c).begin(),(c).end()), (c).end());
#define P(p) cout<<(p)<<endl;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x;
    cin >> x;
    if (x == 7 || x == 5 || x == 3) {
        P("YES");
    }
    else {
        P("NO");
    }

    return 0;
}
