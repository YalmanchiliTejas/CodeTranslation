#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<cmath>
 
#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define reps(i,x) for(int i=1;i<=(int)(x);i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(int i=((int)(x));i>0;i--)
 
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 2e9
#define MOD 1000000007
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef std::pair<ll, ll> P;
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}
 
 
using namespace std;

int main()
{
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 0;
    if(a+b>=2*c){
        ll p0 = 0;
        ll p1 = 0;
        if(x>=y) {p0 += (x-y)*a; p1 += 2*x*c;}
        else {p0 += (y-x)*b; p1 += 2*y*c;}
        p0 += 2*min(x, y)*c;
        ans = min(p0, p1);
    }else{
        ans += x*a + y*b;
    }
    cout << ans;
}