#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define INF (ll)1e18
#define MOD (ll)1e9 + 7
#define pb push_back

typedef long long ll;
typedef long long int llt;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int typea = a * x + b * y, typeb, typec;
    if(x>=y){
        typeb = c * 2 * y + a * (x - y);
        typec = c * 2 * x;
    }
    if(x<y){
        typeb = c * 2 * x + b * (y - x);
        typec = c * 2 * y;
    }
    cout << min(typea, min(typeb, typec)) << endl;
    return 0;
}