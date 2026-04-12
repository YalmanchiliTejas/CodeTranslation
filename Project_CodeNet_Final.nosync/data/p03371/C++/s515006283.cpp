#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;
typedef vector<pair<int,int>> vii;
typedef vector<vector<int>> vvi;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main (void) {
    ios_base::sync_with_stdio(false);

    int a,b,c,x,y;
    int ans = 1e9;

    cin >> a >> b >> c >> x >> y;

    ans = min(ans, a*x+b*y);
    if (x < y) {
        ans = min(ans, 2*c*x+(y-x)*b);
        ans = min(ans, 2*c*y);
    } else {
        ans = min(ans, 2*c*y+(x-y)*a);
        ans = min(ans, 2*c*x);
    }

    cout << ans << endl;

    return 0;
}
