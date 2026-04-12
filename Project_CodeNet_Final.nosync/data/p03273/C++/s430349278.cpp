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
    
    int h,w; cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vector<bool> tate(h,true),yoko(w,true);
    rep(i,h) rep(j,w) if(a[i][j] == '#') tate[i] = false,yoko[j] = false;
    rep(i,h){
        if(tate[i]) continue;
        rep(j,w){
            if(yoko[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}

