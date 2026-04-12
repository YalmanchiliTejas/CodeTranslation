#include<bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
typedef long long int ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<vi > vvi;
typedef std::vector<vll > vvll;
typedef std::pair<int,int> ii;
typedef std::pair<int, ii > iii;
typedef std::pair< ll, ll > lp;
typedef std::vector<ii> vii;
typedef std::vector<vii > vvii;
 
#define int ll
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define mp make_pair
#define ub(a,b) upper_bound(all(a),b)
#define lb(a,b) lower_bound(all(a),b)
#define bs(a,b) binary_search(all(a),b)
#define mem(a,b) memset(a,b,sizeof(a))
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define in1(a,n) F(i,1,n)cin>>a[i]
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<endl
#define ff first
#define ss second
#define F(i,a,b) for (ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define rep(i,n) F(i,0,n-1)
#define clr(a) (a).clear()
#define rz resize
#define sqr(a) ((a) * (a))
#define sz(a) int((a).size())
#define len(a) int((a).length())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin() ,(a).rend()
#define endl '\n'
 
#define mod 1000000007
// #define mod 998244353
 
inline int add(int a, int b){a += b; if(a >= mod)a -= mod; return a;}
inline int sub(int a, int b){a -= b; if(a < 0)a += mod; return a;}
inline int mul(int a, int b){return (int)((long long) a * b %mod);}
inline int poww(int a, int b){int res = 1; while(b > 0){ if(b & 1)res = mul(res, a); a = mul(a, a);b /= 2;} return res;}
inline int inv(int a){return poww(a, mod - 2);}
int gcd(int a, int b, int &x, int &y){if(a == 0){x = 0, y = 1; return b;} int x1, y1;  int d = gcd(b%a, a, x1, y1); x = y1 - (b/a) * x1; y = x1; return d;}
 
// #################################### matrix operations ####################################
inline vvi matmul(vvi A, vvi B) {int p = A.size(), q = A[0].size();int r = B.size(), s = B[0].size();assert(q == r);vvi C(p, vi(s, 0LL));
	rep(i, p){rep(j, s){rep(k, q){
				// C[i][j] += A[i][k] * B[k][j]; 
				C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
	}}}return C;}
 
inline vvi matpow(vvi A, int n){int p = A.size(), q = A[0].size();assert(p == q);vvi res(p, vi(p, 0));rep(i, p)res[i][i] = 1;while (n){if (n&1)res = matmul(res, A);A = matmul(A, A);n >>= 1;}return res;}
 
// ###########################################################################################
 
// #################################### Combinatorics template ###############################
struct factorial{
	int N;int *fac;int *ifac;int MOD;
	factorial(int n, int m = 1000000007){N = n;MOD = m;fac = new int[1+N];ifac = new int[1+N];pre_calc();}
	int add(int a, int b){a += b; if(a >= MOD)a -= MOD; return a;}
	int subtract(int a, int b){a -= b; if(a < 0)a += MOD; return a;}
	int multiply(int a, int b){return (int)((long long) a * b %MOD);}
	int binpow(int a, int b){int res = 1; while(b > 0){ if(b & 1)res = multiply(res, a); a = multiply(a, a);b /= 2;} return res;}
	int inverse(int a){return binpow(a, MOD - 2);}
	void pre_calc(){fac[0] = ifac[0] = 1;for (int i = 1 ; i <= N ; i++){fac[i] = multiply(fac[i-1], i);ifac[i] = multiply(ifac[i-1], inverse(i));}}
	int ncr(int n , int r){return multiply(fac[n], multiply(ifac[r], ifac[n-r]));}
};
// ###########################################################################################
 
// ##################################### Fenwick Tree template ###############################
struct fenwick_tree{
	int *bit;int n;
	fenwick_tree(int n){this->n = n;this->bit = new int[n+1];}
	void add(int i, int v){for (; i<=this->n; i+= i&-i)this->bit[i] += v;}
	int get(int i){int s = 0;for (; i; i -= i&-i){s += this->bit[i];}return s;}
};
// ###########################################################################################
 
// ######################################## Policy-based DS ##################################
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
 
// template<class key, class value = null_type, class cmp = std::less<key>>
// using ordered_tree = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)
 
// ###########################################################################################
 
#define trace(x) cout<<#x<<" :: "<<x<<endl;
#define trace2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define trace3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define trace4(x,y,z,w) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<endl;
 
//end of template

int MinimumNumIncreasingSubsequences(int arr[], int n) 
{ 
    multiset<int> last; 
  
    // last element in each  increasing subsequence  
    // found so far 
    for (int i = 0; i < n; i++) { 
  
        // here our current element is arr[i] 
        multiset<int>::iterator it = last.lower_bound(arr[i]); 
  
        // iterator to the first element larger  
        // than or equal to arr[i] 
        if (it == last.begin()) 
  
            // if all the elements in last larger 
            // than or to arr[i] then insert it into last 
            last.insert(arr[i]); 
  
        else { 
            it--; 
  
            // the largest element smaller than arr[i] is the number 
            // before *it which is it-- 
            last.erase(it); // erase the largest element smaller than arr[i] 
            last.insert(arr[i]); // and replace it with arr[i] 
        } 
    } 
    return last.size(); // our answer is the size of last 
} 
signed main(){
	crap;
	int n;
	cin >> n;
	int a[n];
	in(a, n);
	int ans = MinimumNumIncreasingSubsequences(a, n);
	cout << ans << endl;

}