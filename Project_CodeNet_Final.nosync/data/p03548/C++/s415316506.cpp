#include "bits/stdc++.h"
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;
const int DIV = 1e9+7;

int x, y, z;

int main(int argc, char const* argv[])
{
    cin >> x >> y >> z;
    int ans = 0;
    while((y + z) * ans <= x - z){
        ans++;
    }
    cout << ans - 1 << endl;
    return 0;
}
