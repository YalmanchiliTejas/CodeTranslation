#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define BR cout<<endl;
#define LEN(s) s.length();
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const ll mod=1000000007;

ll powmod(ll x,ll y){
    ll res=1;
    for(ll i=0;i<y;i++){
        res=res*x%mod;
    }
    return res;
}

int main(){
    int a, b, c, x, y, ans = 0;
    cin >> a >> b >> c >> x >> y;

    if(a + b > 2 * c){
        int num = min(x, y);
        x = x - num;
        y = y - num;
        ans = num * 2 * c;
    }
    else{
        cout << a * x + b * y << endl;
        return 0;
    }
    
    if(a * x + b * y > 2 * c * (x + y))cout << ans + 2 * c * (x + y) << endl;
    else cout << ans + a * x + b * y << endl;

    return 0;
}

