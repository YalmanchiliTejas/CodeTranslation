#include <bits/stdc++.h>
using namespace std; 

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long ll; 
typedef long double ld; 
typedef pair<int,int> p32;   
typedef pair<ll,ll> p64;  
typedef pair<double,double> pd; 
typedef pair<ld,ld> pld; 
typedef vector<int> v32;  
typedef vector<ll> v64;  
typedef vector<pd> vpd;   
typedef vector<p32> vp32;  
typedef vector<p64> vp64;  
typedef vector<v32> vv32;  
typedef vector<v64> vv64;  

#define pb push_back
#define mp make_pair
#define prarr(a,n) cerr<<#a<<" : ";for(ll i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define prmat(mat,row,col) cerr<<#mat<<" :\n";for(ll i=0;i<row;i++) {for(ll j=0;j<col;j++) cerr<<mat[i][j]<<"\t";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
#define all(a) a.begin(),a.end()
#define sz(x) ((int)x.size())
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(NULL); cin.tie(NULL)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {ll idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
template <class T> void prall(T a) { prc(all(a)); }

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

const int inf=1000*1000*1000+9; 
const ll infl=1ll*inf*inf; 
int mod=1000*1000*1000+7;  
// ----------------------------------------------------------------------------	-------------- 

void pre(){
}

void solve(){
  int n; cin>>n;
  vector<map<int,ll>> dp(n+1); 
  v32 vals(n+1); 
  for(int i=1;i<=n;i++) cin>>vals[i]; 
  dp[1][1]=vals[1]; 
  dp[2][1]=max(vals[2],vals[1]); 
  for(int i=3;i<=n;i++){
    for(int j=-2;j<=2;j++){
      int up=i/2+(i%2); 
      int prevup=(i-1)/2+(i-1)%2; 
      if(i/2+j<=up){
        dp[i][i/2+j]=max((i/2+j<=prevup)?dp[i-1][i/2+j]:-infl,dp[i-2][i/2+j-1]+vals[i]); 
      }
    }
  }
  cout<<dp[n][n/2]<<endl; 
}



int main(){
	// clock_t beg=clock(); 
  fast_io; 
  int testcases=1; 
  pre(); 
  // cin>>testcases; 
  cout << fixed << setprecision(13); 
  int cs=0; 
  while(testcases--){
    cs++; 
    // cout<<"Case #"<<cs<<": "; 
    solve(); 	
  }
	// clock_t end=clock(); 
	// fprintf(stderr, "%lf\n", (double)(end-beg)/(CLOCKS_PER_SEC));
}



