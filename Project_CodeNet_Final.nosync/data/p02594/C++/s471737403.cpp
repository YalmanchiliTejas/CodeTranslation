#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forr(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define foriter(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define endl '\n'
#define INF (ll)(1e9)
#define EPS 1e-9
#define MOD (ll)(1e9+7)
#define PI 3.1415926535897932384626433832795
#define set set
#define mset multiset
#define uset unordered_set
#define umset unordered_multiset
#define map map
#define mmap multimap
#define umap unordered_map
#define ummap unordered_multimap

using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vll;
typedef vector<vll> vvll;
typedef pair<i64, i64> pll;

int inp(){
  int x; 
  cin>>x;
  return x;
}

//=============================================================================//

void solve() {
    int x; cin>>x;
    cout<<(x>29? "Yes":"No");
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int T=1;
    //cin >> T;
    while (T--) {
        solve();
        cout<<endl;
    }
    
    return 0;
}