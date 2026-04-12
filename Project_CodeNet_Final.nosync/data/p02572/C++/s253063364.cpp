#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<long long> vl;
typedef vector<vector<ll>> vll;
typedef vector<bool> vb;
typedef set<int> si; 
typedef queue<int> qi;
typedef stack<int> sti;
typedef priority_queue<int> pqi;
#define fori(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,b,a) for(int i = (b); i >= (a); --i)
#define all(a) (a).begin(), (a).end()
//#define __builtin_popcountll bitCountLL
//#define __builtin_popcount bitCount
//__builtin_ctz 末尾0的个数, __builtin_clz 前导0的个数
//__builtin_ffs 最后一个1的位置
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
//std::uniform_int_distribution<long long> rg(1,1e18);
#define maxn 100005
#define Mod 1000000007
const int INF = 2e9;
const ll ML = 4e18;
    
void solve() {
    int n;
    cin >> n;
    vl a(n);
    fori(i,0,n) cin >> a[i];
    ll sum = 0;
    fori(i,0,n) {
        sum += a[i];
    }
    ll ans = 0;
    fori(i,0,n) {
        sum -= a[i];
        ans = (ans + a[i] * (sum % Mod)) % Mod;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	//cout.precision(30); cout << fixed;
	//freopen("D:\\data_in.txt", "r", stdin);
   
    solve();
   
    /*
    clock_t start,finish;
    start = clock();
    
    finish = clock();
    cout << "\n" << (double)(finish - start) / (double)(CLOCKS_PER_SEC) * 1000 << "ms" << endl;
    */
    return 0;
}

/***************************************************************
 question:
 idea:
 tag:
 record:
 ***************************************************************/
