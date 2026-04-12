#include<bits/stdc++.h>

using namespace std;

#define debug(x) cout << '[' << #x << " is: " << x << "] " << '\n';
#define imod(a , n) (a % n + n ) % n

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define inF freopen("milkvisits.in","r",stdin );
#define outF freopen("milkvisits.out" , "w" , stdout ) ;
#define sor(v) sort(v.begin() , v.end());
#define print(v) for(auto f : v ) cout << f << " " ;
#define rsor(v) sort(v.rbegin() , v.rend());
#define rev(v) reverse(v.begin() , v.end());
#define lp(i , n) for(int x = i ; x < n ; x ++)
#define ll long long
#define read(arr , x , n) for(int i = x ; i < n ; i ++ )cin >> arr[i];
const double eps = 1e-6 , PI = acos(-1) ;
const long long OO = 1e18 ;
const ll N = 22  , oo = 1e9 + 1  , M = 2000002, mod = 1e9 + 7 , K = 12;


//                                                +_+
int32_t main(){
    // inF;outF;
    fastio;
    // Dont Forget memset
    ll n , sum = 0 ;
    cin >> n ;
    vector<ll>v(n);
    for(auto &it : v){
        cin >> it ;
        sum += it ;
    }
    ll ans = 0 ;
    for(auto f : v){
        sum -= f ;
        ans += (sum % mod ) * f ;
        ans %= mod ;
    }
    cout << ans ;
}
