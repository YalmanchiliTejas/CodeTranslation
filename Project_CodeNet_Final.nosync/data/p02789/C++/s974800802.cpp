#include <bits/stdc++.h>
#define fr first
#define pb push_back
#define skip continue
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define vi vector<ll>
#define MAX 1e9 + 1234

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int const INF = 1e5 + 9 ;
const int N = 100100;

void faster(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int simple( int n ) {
    int i, sq;
    if ( n%2 == 0 ) { return 0; }
    sq= (int)sqrt( n );
    for ( i= 3; i<=sq; i++ ) {
    if ( (n%i) == 0 ) { return 0; }
    }
    return 1;
}
ll gcd(ll a, ll b){
    if(a > b)	swap(a, b);
    if(!a)	return b;
    return gcd(b % a, a);
}



void solve() {
    ll n , m;
    cin >> n >> m;
    if(n == m){
        cout << "Yes";
    }
    else cout << "No";
}

int main(){
    faster();
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
}
