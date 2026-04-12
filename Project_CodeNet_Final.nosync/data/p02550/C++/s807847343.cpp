#include<bits/stdc++.h>
using namespace std;
 
#define 	pi 				        3.14159265358979
#define 	mod 			        1000000007
#define 	ll  			        long long
#define 	rep(i, a, b) 	        for(ll i = a ; i < b ; i++)
#define     repn(i, a, b)           for(ll i = a ; i > b ; i--)
#define 	mod1 			        1000003
#define     mod2                    998244353
#define 	hi   			        "hello"
#define 	nl 				        "\n"
#define 	ws 				        " "
#define 	ff 				        first
#define 	ss 				        second
#define 	pb 				        push_back
#define 	B 				        begin()
#define     RB                      rbegin()
#define 	E 				        end()
#define     UB                      upper_bound
#define     LB                      lower_bound
#define 	all(v) 			        v.begin(), v.end()
#define 	reset(a, val) 	        memset(a, val, sizeof(a))
#define     pll                     pair<ll, ll>
#define     vll                     vector<ll>
#define     vpll                    vector<pll>
#define 	vs 				        vector<string>
#define     vc                      vector<char>
#define     sqr(a)                  ((a)*(a))
#define 	print1(a) 		        for(auto i : a)cout<<i<<" ";cout<<"\n"
#define 	print2(a) 		        for(auto i : a)cout<<i;cout<<"\n"
#define 	print3(a) 		        for(auto i : a)cout<<i<<nl;
#define 	boost 			        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// ostringstream str1;
// str1 << n;
// string tmp = str1.str();
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
 
bool compare(const pair<string, int>&a, const pair<string, int>&b){ return a.second<b.second; }
 
double logn(double n, double r) { return (n > r - 1) ? 1 + logn(n / r, r) : 0; }
 
vll pwx(10);
void cal(ll x){ pwx[0] = 1; rep(i, 1, 10)pwx[i] = x*pwx[i-1]; }
 
/* ################################################################ */

#define space 200005

void solve() {
    ll n, x, m;
    cin >> n >> x >> m;
    map<ll, ll> mp;

    if(x == 0) {
        cout << 0 << nl; return;
    }

    ll ans = x, pos = 1;
    mp[x] = pos;
    ll i = 2;
    vll arr(1, 0); arr.pb(x);
    if(m == 1) {
        cout << x << nl; return;
    }

    for(i = 2 ; i <= n ; i++) {
        x = (sqr(x) % m);
        if(mp[x] > 0) {
            break;
        }
        arr.pb(x);
        mp[x] = ++pos;
        ans += x;
    }

    if(i != n+1 && x) {
        for(ll j = 1 ; j < arr.size() ; j++) 
            arr[j] += arr[j-1];

        if(x == 1) {
            ans += (n - pos);
        }
        else {
            n -= pos;
            // cout << n << ws << mp[x] << ws << arr.back() << ws << arr[mp[x] - 1]<< nl;
            ans += (n/(pos+1 - mp[x])) * (arr.back() - arr[mp[x] - 1]);

            n %= (pos+1 - mp[x]);
            // cout << n << nl;
            ans += arr[mp[x] + n - 1] - arr[mp[x] - 1];
        }
    }

    cout << ans << nl;
}

int main(){
    boost;
    // cal(3);

    // // For getting input from input.txt file 
    // freopen("alchemy_input.txt", "r", stdin); 
  
    // // Printing the Output to output.txt file 
    // freopen("output.txt", "w", stdout);

    int t = 1, k = 1;
    // cin>>t;
    while(t--){
        // cout<<"Case #"<<k<<": ";
        solve();
        k++;
    }
}
