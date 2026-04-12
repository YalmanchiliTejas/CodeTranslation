#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
#define VIin(a) for(int i=0; i<a.size(); i++) cin >> a[i]
typedef vector<int> VI;
typedef vector<VI> VVI;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
/*最大公約数*/int gcd(int x, int y) { return y ? gcd(y,x%y) : x;}
/*最小公倍数*/int LCM(int a, int b) { int g = gcd(a, b); return a / g * b; }
//----------------------------------------------
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x,y,z; cin >> x >> y >> z;
    cout << (x - z) / ( y + z) <<endl;

    return 0;
}