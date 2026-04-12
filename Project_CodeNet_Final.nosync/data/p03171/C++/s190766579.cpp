/********************************
*** ******** ********** *********
*** * ****** ********* * ********
*** ** ***** ******** *** *******
*** *** **** ******* ***** ******
*** **** *** ****** ******* *****
*** ***** ** ***** +++++++++ ****
*** ****** * **** *********** ***
*** *******  *** ************* **
*** ******** ** *************** *
**********_**********************
* |   /  / \  \     /    /\     *
* |  /  |   |  \   /    /  \    *
* | /   |   |   \ /    /    \   *
* |+\   |   |    |    /______\  *
* |  \  |   |    |   |        | *
* |   \  \_/     |   |        | *
********************************/
#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 1000002
#define fi first
#define se second
#define se second
#define lsb(i) (i & -i)
#define Pi 3.141592653589793238
#define nl cout<<'\n'
#define TEST cout<<"TEST",nl
#define all(a) a.begin(), a.end()
#define remax(a, b) (a = ((a<b) ? b : a))
#define remin(a, b) (a = ((a<b) ? a : b))
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define precise(a) cout<<fixed<<setprecision(a)
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define P pair<lli,pr>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

lli lcm(lli a,lli b){
    return ((a*b)/__gcd(a,b));
}

const lli N = 3005;
lli a[N], n, dp[N][N];

lli fun(lli l, lli r){
    if(l==r) return a[l];
    if(dp[l][r]!=-1) return dp[l][r];
    lli ans = max(a[l]-fun(l+1,r),a[r]-fun(l,r-1));
    return dp[l][r] = ans;
}
void solve(){
    cin >> n;
    NA(i,0,n) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << fun(0,n-1);
    return;
}

int main(){
    fastIO; 
    lli t = 1; 
    // cin>>t;
    NA(i,0,t) {
        solve();
    }
    return 0;
}
