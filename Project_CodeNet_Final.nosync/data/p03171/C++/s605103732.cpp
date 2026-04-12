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
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define ios	    	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp 			make_pair
#define lb 			lower_bound
#define ub			upper_bound
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ini(a,n,b)	for(ll int i=0;i<n;i++) a[i]=0;
#define hell 		(ull)1e9
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define f1 first
#define s1 second
#define N 1005
using namespace std;
 
void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

 
int main(void){
    boost();
    ll n;
    cin>>n;
    vi v(n);
    rep(i,0,n)
        cin>>v[i];
    ll a[n][n];
    rep(i,0,n)
        a[i][i] = v[i];
    ll j;
    for ( int d1 = 2 ; d1 <= n ; d1++){
        for ( int i = 0; i < n - d1 + 1; i++){
            j = i + d1 - 1;
            if (d1 == 2){
                a[i][j] = abs(v[i] - v[j]);
                a[j][i] = abs(v[i] - v[j]);
            }
            else{
                a[i][j] = max(v[i] - a[i+1][j] , v[j] - a[i][j-1]); 
                a[j][i] = max(v[i] - a[i+1][j] , v[j] - a[i][j-1]); 
            }
        }
    }
    cout<<a[0][n-1];
    // rep(i,0,n){
    //     rep(j,0,n)
    //         cout<<a[i][j]<<" ";
    //     cout<<"\n";
    // }
}