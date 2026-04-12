#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);

    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans=a*x+b*y;
    if (x>y) {
        swap(x,y);
        swap(a,b);
    }
    ans=min(ans,b*(y-x)+2*c*x);
    ans=min(ans,2*c*y);
    cout << ans << endl;

    return 0;
}