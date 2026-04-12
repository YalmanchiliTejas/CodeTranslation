/* << IN THE NAME OF GOD >> */
#include <bits/stdc++.h>
using namespace std;



#define err(x) cerr << #x  << " = "<<  x << '\n'
#define out(x) cout << x << '\n'
#define forp(i, r, l) for(int i = int(r); i < int(l); i++)
#define forn(i, r, l) for(int i = int(r); i > int(l); i--)
#define FAST ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll ,ll> pll;
const int maxn = 1e6 + 120;
 



int a ,b ,c ,x ,y ,res;

int main(){FAST;
    cin >> a >> b >> c >> x >> y;
    c *= 2;
    int minx = min(x ,y);
    if(c  <= a + b)
        res += minx * c,    x -= minx ,y -= minx;

    int val = min(a ,c);
        res += val * x;
    val = min(b ,c);
        res += y * val;

    out(res);
   return 0;
}
 










