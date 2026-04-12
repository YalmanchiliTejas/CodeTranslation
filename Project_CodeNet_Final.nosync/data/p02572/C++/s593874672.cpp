#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"

#define rep(i,n) for (int i = 0; i < n; i++)
#define repd(i,n) for (int i = n-1; i >= 0; i--)
#define fo(i,a,b) for (int i = a; i < b; i++)
#define fod(i,a,b) for (int i = a; i >= b; i--)
#define umap unordered_map<int,int>
#define mii map<int,int>
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define pqMin priority_queue<int,vector<int>,greater<int>>
#define pqMax priority_queue<int>
#define pqpii priority_queue<pii>
#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define w(t) int t; cin>>t; while (t--)
#define out(x, y) cout << x << " " << y << endl
#define print(x) cout << x << endl
#define ps(x,y) fixed<<setprecision(y)<<x
#define pprint cout<<"Case #"<<tt<<": ";
const int mod = 1e9+7;
const int N = 2e5;
const int inf = 1e18;

int add(int a,int b){int res=(a+b)%mod;return (res<0)?res+mod:res;}
int mul(int a,int b){int res=(a*1LL*b)%mod;return (res<0)?res+mod:res;}
bool compare (int x, int y) { return x > y;}

struct Compare {
    bool operator () (pii A, pii B) {
        return A.first > B.first;
    }
};
 struct tri{
   int x,y,z;
 };
 struct cmp{
bool operator ()(tri a,tri b){
    if(a.x==b.x)
        return a.y>b.y;
    return a.x<b.x;

}};
bool comp(pii a,pii b){
    if(a.first>b.first) return true;
    else if(a.first==b.first) return a.second<b.second;
    else return false;

}
int binarySearch(vector<int>nums, int lo, int hi, int target) {
        while (lo < hi) {
            int mid = (lo + hi)/2;
            if (nums[mid] <= target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }

void solve() {

    int t = 1;
    //cin >> t;
    while(t--){
      int n;
      cin>>n;
      int s=0,ans=0;
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin>>v[i];
        s=(s+v[i])%mod;
      }
      for(int i=0;i<n;i++){
        s=(s-v[i]+mod)%mod;
        ans=(ans+((s*v[i])%mod))%mod;
      }
      cout<<ans;

    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

   /* #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);1

    freopen("output.txt", "w", stdout);
    #endif*/

    solve();

    return 0;
}
