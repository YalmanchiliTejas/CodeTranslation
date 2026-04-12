#include<bits/stdc++.h>
//priority_queue<ll, vector<ll>, std::greater<ll> > q;
#define ull 		unsigned long long
#define ll 			long long
#define M 			1000000007
#define pb 			emplace_back
#define p_q 		priority_queue
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (ll)x.size()
#define endl        '\n'
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) // gcd((a),(b))
#define ios	    	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp 			make_pair
#define lb 			lower_bound
#define ub			upper_bound
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ini(a,n,b)	for(ll int i=0;i<n;i++) a[i]=0;
#define hell 		(ull)1e9
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
using namespace std;
//ll maxi = 3005;
ll dp[3005][3005];
void boost()
{
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    cout.tie(NULL);
}



int main(void)
{
    boost();
    ll n;
    cin>>n;
    vi v(n);
    rep(i,0,n)
        cin>>v[i];
    
    for (ll l = n-1; l>=0;l--){
        for (ll r = l;r < n;r++){
            if(l == r) {

                dp[l][r] = v[l];

            }

            else {

                dp[l][r] = max(v[l] - dp[l+1][r], v[r] - dp[l][r-1]);

            }
        }
    }

    cout<<dp[0][n-1];
   
}   