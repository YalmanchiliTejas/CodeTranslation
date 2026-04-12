#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int mpow(int base, int exp);
typedef  vector<int> vi;
typedef  vector<ll> vll;
typedef  vector<pair<ll,ll>> vpll;
typedef  vector<pair<int, int>> vpii;
typedef  pair<int, int> pii;
typedef  pair<ll, ll> pll;
typedef  unordered_map<ll, ll> umpll;
typedef  unordered_map<int, int> umpii;
typedef  unordered_map<ll, int> umpli;
typedef  unordered_set<int> usi;
typedef  unordered_set<ll> usll;
typedef  set<int> si;
typedef  set<ll> sll;
typedef  set<pair<int, int>> spii;
typedef  set<pair<ll, ll>> spll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fo(i,n) for(i = 0;i < n; i++)
#define Fo(i,k,n) for(i = k;k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", "<< #z << " = " << z << endl

ll randGen(ll lower, ll upper) { return (rand() % (upper - lower + 1)) + lower; }
ll dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// cout << fixed;
// cout.precision(10);
//******************          Function here          *********************//

   void solve(){
      int n;
      cin >> n;
      ll a[n], sum[n];
      for(int i = 0; i < n; i++) {
         cin >> a[i];
         sum[i] = a[i];
      }
      for(int i = n - 2; i >= 0; i--) {
         sum[i] += sum[i + 1];
         sum[i] %= MOD;
      }
      ll ans = 0;
      for(int i = 0; i < n - 1; i++) {
         ans += (a[i] * sum[i + 1]) % MOD;
      }
      cout << (ans % MOD) << endl;
   }

//*********************************************************************//

int main()
{
    #ifndef ONLINE_JUDGE
      string inputFile, outputFile;
      inputFile = "input.txt";
      outputFile = "output.txt";
      freopen(inputFile.c_str(), "r", stdin);
      freopen(outputFile.c_str(), "w", stdout);
    #endif

    int t = 1;
    // cin>>t;
    while(t-- >0){
      solve();
    }
    return 0;
}



/**********************   Utility Functions  *****************************/
   int mpow(int base, int exp) {
     base %= MOD;
     int result = 1;
     while (exp > 0) {
       if (exp & 1) result = ((ll)result * base) % MOD;
       base = ((ll)base * base) % MOD;
       exp >>= 1;
     }
     return result;
   }
/***********************************************************************/
