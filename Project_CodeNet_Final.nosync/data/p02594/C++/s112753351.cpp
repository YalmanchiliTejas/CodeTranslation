#include<bits/stdc++.h>

using namespace std;

#define pb            push_back
#define mp            make_pair
#define po            pop_back
#define fi            first
#define se            second
#define mxn           100005
#define ll            long long int
#define ldb           long double
#define fr(i,a,b,k)   for(int i=a ; i<b ; i+=k)
#define frr(i,a,b,k)  for(int i=a ; i>b ; i-=k)
#define all(v)        v.begin(),v.end()
#define endl          "\n"
#define deg(x)        cout<<endl<<#x<<" = "<<(x)<<endl;
#define casep(x)      cout<<"Case #"<<(x)<<": ";
#define fast          ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));

typedef pair<ll,ll> pp;
typedef vector<int> vi;
typedef vector<pp> vpp;
typedef vector<vi> vvi;

const int inf = 1e9+7;
const int minf = (-1)*(1e9+7);

ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
ll gcd(ll a,ll b){ return __gcd(a,b);}
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}


void solve(int test){

    ll x;
    cin >> x;
    (x>=30)?cout << "Yes":cout << "No";

}

int main(){

    fast;
    int t=1;
    // cin >> t;
    for(int i=1 ; i<=t ; i++){
        solve(i);
        cout << endl;
    }
    return 0;
}
