#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repe(i, n) for (int i = 0; i <= (int)(n); i++)
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define ANS cout << ans << endl
#define all(a) a.begin(),a.end()
#define SORT(a) sort(all(a))
#define REVERSE(a) reverse(all(a))
#define int long long
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORe(i, m, n) for(int i = m;i <= n;i++)
#define VIin(a) for(int i=0; i<a.size(); i++) cin >> a[i]
#define OUT(a) cout << a << endl
typedef vector<int> VI;
typedef vector<VI> VVI;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
/*最大公約数*/int gcd(int x, int y) { return y ? gcd(y,x%y) : x;}
/*最小公倍数*/int lcm(int a, int b) { int g = gcd(a, b); return a / g * b; }
/*素数判定*/int isPrime(int n){if(n<2){return 0;}for(int i=2; i*i<=n; i++){if(n%i==0){return 0;}}return 1;}
/*約数列挙*/vector<int> getDivisor(int n){vector<int> v; for(int i=1; i*i<=n; i++){if(n%i==0){v.push_back(i);if(i!=n/i){v.push_back(n/i);}}}sort(v.begin(),v.end()); return v;}
//----------------------------------------------
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    int ans = 0;
    int m = min(x,y);
    ans += m*min(a+b,c*2);
    if(x < y) ans += (y-m)*min(b,c*2);
    else if(x > y) ans += (x-m)*min(a,c*2);
    ANS;

    return 0;
}