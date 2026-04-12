#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define INF 1000000001
#define inf1 1000000000000000001
#define MOD 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 100005
#define M 3009
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<ll,ll>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"
using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}






void test_case() {

   ll n;
   cin>>n;


   vecl arr(n);
   rep(i,n) {
       cin>>arr[i];
   }

   ll dp[n][n];

   memset(dp,0,sizeof(dp));

   ll sum =0;

   for(auto it : arr) {
       sum+= it;
   }

   for(int i=0; i+1<n; i++) {
       dp[i][i] = arr[i];
       dp[i][i+1] = max(arr[i], arr[i+1]);
   }

   dp[n-1][n-1] = arr[n-1];

   for(ll d = 0; d<n; d++) {
       for(ll i=0, j=d; j<n; i++,j++) {

           ll x = ((i+2 <= j)) ? dp[i+2][j] : 0;
           ll y = ((i+1 <= j-1)) ? dp[i+1][j-1] : 0;
           ll z = ((i <= j-2)) ? dp[i][j-2] : 0;

           dp[i][j] = max(arr[i] + min(x,y), arr[j] + min(y,z));
       }
   }

    ll ans = dp[0][n-1] - sum;
    ans+= dp[0][n-1];
   cout<<ans<<endl;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(20);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int t = 1;
    //cin >> t;
    while(t--)
    {   
        test_case();
    }
}
