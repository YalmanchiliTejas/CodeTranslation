#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans =a*x+b*y;
    ll mi = min(x,y);
    ll ma = max(x,y);
    ans = min(ans,ans-mi*(a+b)+2*mi*c);
    ans = min(ans,2*c*ma);
    cout << ans << endl;
    return 0;
}