#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define mt make_tuple
#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define pb push_back
//#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)((x).size()))
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define scanVec(vec) for(int i = 0; i < SZ(vec) ; i++){ cin >> vec[i];}
#define printVec(vec) for(int i = 0; i < SZ(vec) ; i++){ cout<<vec[i]<<" ";}
#define mod(a,b) ((a%b +b)%b)
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
//#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define lastEle(vec) vec[vec.size()-1] 
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) 
#define ll long long 
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define INF 1001001001
//#define PI 3.1415926535897932384626
 
using namespace std;
 using namespace __gnu_pbds;
 template <typename T>
 using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
 
/*
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
 */
//----------------------------------------------------------------------------------------------------------------------
 
void swap(int & a, int & b){
    auto temp = a;
    a = b;
    b = temp;
}
 
const ll MOD = 1e9 + 7;
 
ll inf = 1LL*1e17;
 
void no(){
    cout <<"NO" << endl;
   //exit(0);
}
 
void yes(){
    cout <<"YES" << endl; //exit(0);
}
 
const ll md = 998244353;

const int MAXN = 3e3 + 10;
// pref and suff
ll dp[MAXN][MAXN];

void sl(){
	int n; cin >> n;
	vector< ll > arr (n); scanVec(arr);
	
	for(int L = n - 1; L >= 0;L--){
		for(int R = L; R < n;R++){
			if(L == R) {
				dp[L][R] = arr[L];
				continue;
			}
			dp[L][R] = max(  -dp[L + 1][R] + arr[L] , -dp[L][R - 1] + arr[R]);
			
		}
	}
	
	cout << dp[0][n-1] << endl;
}

 
int main(){
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ts = 0;
    if(ts == 1) cin >> ts;
    else ts = 1;
    while(ts--) sl(); 
    return 0;
} 
