#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip> 
#include <algorithm>
#include <queue>
#include <list>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
 
using namespace std;
 
#define sz(a) int((a).size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define endl '\n'
#define watch(x) cout << #x << " : " << x << endl;
 
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef vector<ii> vii;
 
const int N = int(2e5)+10;
const int K = 10005;
// const int MOD = int(1e9)+7;
const int INF = int(1e9)+5;
const ll INF64 = 1e18;

const ll MOD = 1e9 + 7;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }

ll a[N];
map<ll,int> mp;

void solve () {
    int x;cin>>x;
    if (x >= 30) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
}

int main () {
    FastIO
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t;
    // cin>>t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}