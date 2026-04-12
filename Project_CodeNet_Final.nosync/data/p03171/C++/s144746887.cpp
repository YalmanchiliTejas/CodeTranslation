#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,pair<ll,ll>> pii;
typedef pair<ll,ll> pi;
typedef vector<ll> vl;

#define matrix vector<vector<ll>>
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define rep(i,n) for(ll (i)=0;(i)<n;++(i))
#define crep(i,m,n) for(ll (i)=m;(i)<n;++(i))
#define zero(a) memset((a),0,sizeof((a)))
#define minus(a) memset((a),-1,sizeof((a)));
#define sq(a) ((a)*(a))
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define ff first
#define ss second

ll global=0;

// return nCr value
long long C(int n, int r) {
    if(r>n) return 0;
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}

// return whether number is prime or not
vector<ll> sieve(ll n){
    vector<ll> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}


void test_case();
int main(){
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    ll t=1;
    // cin >> t;
    for(ll T=0;T<t;T++){
        test_case();
    }
    //**************************************************************************//
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

void test_case(){
    ll n;scanf("%lld",&n);
    vector<ll>a(n);
    rep(i,n)scanf("%lld",&a[i]);
    vector<vector<ll>>dp(n+5, vector<ll>(n+5));
    for(ll L = n-1; L>=0 ; --L){
        for(ll R = L; R<=n-1; ++R){
            if(L==R){
                dp[L][R] = a[L];
            }
            else{
                dp[L][R] = max(a[L]-dp[L+1][R], a[R]-dp[L][R-1]);
            }
        }
    }
    cout<<dp[0][n-1];
}
