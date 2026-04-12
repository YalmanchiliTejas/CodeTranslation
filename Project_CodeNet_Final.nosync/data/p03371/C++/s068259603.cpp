#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = LINF;
    for(int i=0;i<=1000000;i++){
        ans = min(ans,(ll)i*2*c+max(0,x-i)*a+max(0,y-i)*b);
    }
    cout << ans << endl;
}