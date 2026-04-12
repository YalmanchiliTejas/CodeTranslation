#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};
void chmin(long long &a, long long b) { if (a > b) a = b; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}
ll modpow(long long a, long long n, long long mod2) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod2;
        a = a * a % mod2;
        n >>= 1;
    }
    return res;
}

int main() {
    int a,b,c,x,y,ans = INT_MAX,x2,y2,x3,y3;
    cin >> a >> b >> c >> x >> y;
    ans = min(ans,a*x+b*y);
    //cout << ans << endl;
    int tmp = 2*min(x,y)*c;  // ABピザの値段
    x2 = (x-min(x,y));
    y2 = (y-min(x,y));
    tmp += a*x2+b*y2;
    ans = min(ans,tmp);
    //cout << ans << endl;

    int tmp2 = 2*max(x,y)*c;
    //x3 = (x-max(x,y));
    //y3 = (y-max(x,y));
    //tmp2 += a*x3+b*y3;
    ans = min(ans,tmp2);

    cout << ans << endl;
    return 0;
}
