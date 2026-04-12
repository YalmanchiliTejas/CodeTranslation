#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;


int main (){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int ans;

    ans = a*x+b*y;

    ans = min(ans,(max(x,y)*2*c));

    int tmp;

    if (x>y) {
        ans = min(ans,(x-y)*a+y*2*c);

    }
    if (x<y) {
        ans = min(ans,(y-x)*b+x*2*c);

    }

    cout << ans << endl;



}


