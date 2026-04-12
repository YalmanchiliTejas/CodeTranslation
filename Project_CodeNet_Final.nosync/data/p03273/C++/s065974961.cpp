#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 2e9
#define LINF 1e18
#define MOD 1000000007
#define PI 3.141592653589793
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define input(x, n)for(ll i = 0; i <(ll)(n); i++)cin >> x[i];
#define until(i,n) for(ll i = 1; i <= (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << "=" << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl

int main(){

    ll h, w;
    cin >> h >> w;

    vector<string> a(h);
    vector<bool> fh(h, 0);
    vector<bool> fw(w, 0);

    for(ll i = 0; i < h; i++){
        cin >> a[i];
        for(ll j = 0; j < w; j++){
            if(a[i][j] == '#'){
                fh[i] = 1; 
                fw[j] = 1;
            }
        }
    }

    for(ll i = 0; i < h; i++){
        bool f = 0;
        for(ll j = 0; j < w; j++){
            if(fh[i] && fw[j])cout << a[i][j];
        }
        if(fh[i])cout << endl;
    }





}