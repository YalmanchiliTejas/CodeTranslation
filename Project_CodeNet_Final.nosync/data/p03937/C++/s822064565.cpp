#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
using namespace std;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*(b/gcd(a, b)); }
template<typename T> T keta(T num){ T k=0; while(num>0){ num/=10; k++; } return k; }
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], ll n){ reps(i, 0, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h;
    char a[10][10];

    rep(y, 10){
        rep(x, 10){
            a[x][y] = '.';
        }
    }

    ll cnt = 0;

    cin >> h >> w;
    rep(y, h){
        rep(x, w){
            cin >> a[x][y];
            if(a[x][y] == '#') cnt++;
        }
    }

    int px=0, py=0;
    bool res = false;
    ll rescnt = 1;
    while(true){
        if(px == w-1 && py == h-1){
            res = true;
            break;
        }
        if(px >= w || py >= h) break;
        if(a[px+1][py] == a[px][py+1]) break;
        else{
            if(a[px+1][py] == '#'){
                px++;
            }else if(a[px][py+1] == '#'){
                py++;
            }
            rescnt++;
        }
    }

    auto solve = [](bool res){
        if(res) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    };

    if(rescnt != cnt) res = false;

    //cout << rescnt sp cnt << endl;

    solve(res);

    return 0;
}
