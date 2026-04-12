#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const ll INF = 1LL << 60;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    vector<ll> p(max(x,y)+1);
    for (int i=0;i <= max(x,y);i++){
        p[i]=2*i*c;
    }
    ll ans=INF;
    for (int i=0;i <= max(x,y);i++){
        ll tmp;
        if (x-i < 0) tmp=(y-i)*b+p[i];
        else if (y-i < 0) tmp=(x-i)*a+p[i];
        else tmp=(x-i)*a+(y-i)*b+p[i];
        ans=min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}