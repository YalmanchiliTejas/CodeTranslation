#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using namespace std::chrono;

#define ll long long
#define ld long double
#define pq priority_queue
#define ff first
#define ss second
#define pb push_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(c) ((ll)c.size())
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define MOD1 998244353
#define MOD2 1000000007

#ifdef LL
const ll INF = 1e18;
#else 
const ll INF = 1e9;
#endif

typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

high_resolution_clock::time_point setTime() { return high_resolution_clock::now(); }
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);} //Just add this as a third argument to sort() while sorting an array of pairs; NO NEED FOR ANY ARGUMENTS;
template <typename T>
T fact(T a, T mod){ int res = 1, i; for (i = 2; i <= a; i++){ res *= i; res%=mod;} return res; }
template <typename T>
ll powmod(T a,T b,ll m){ ll ans=1; while(b>0){if(b&1){ans*=a;ans%=m;}a*=a;a%=m;b>>=1;} return ans; }
template <typename T>
ll power(T a, T b){ ll ans=1; while(b>0){if(b&1){ans*=a;}a*=a;b>>=1;}return ans;}
template <typename T>
T max3(T a, T b, T c) { return max((max(a,b), max(b,c))); }
template <typename T>
T min3(T a, T b, T c) { return min((min(a,b), min(b,c))); }
template <typename T>
T mid3(T a, T b, T c) { return a+b+c-max3(a,b,c)-min3(a,b,c); }
template <typename T>
T mid(T a, T b) { return min(a,b)+((max(a,b)-min(a,b))/2); }
template <typename T>
T gcd(T a,T b){ return (b?__gcd(a,b):a); }
template <typename T>
T lcm(T a, T b){ return (a*(b/gcd(a,b))); }
template <typename T>
T cl(T a, T b){ return (a+b-1)/b; }
template <typename T>
T to_upper(T s){ return transform(s.begin(), s.end(), s.begin(), ::toupper); }
template <typename T>
T to_lower(T s){ return transform(s.begin(), s.end(), s.begin(), ::tolower); }

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = setTime();

    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll dp[n][n];
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j) dp[i][j] = a[i];
            else
            {
                dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]); //this does not mean anything
            }
        }
    }

    cout<<dp[0][n-1]<<endl;

    auto stopTime = setTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
