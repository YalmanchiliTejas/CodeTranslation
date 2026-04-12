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

int a, b, c, x, y;

int main()
{
    cin >> a >> b >> c >> x >> y;

    if(a + b <= 2 * c){
        cout << x * a + y * b << endl;
    }
    else{
        int num = min(x, y);
        int dx = x - num;
        int dy = y - num;
        cout << c * 2 * num + min(dx * a, c * 2 * dx) + min(dy * b, c * 2 * dy) << endl;
    }

    return 0;
}