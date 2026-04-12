#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define FINOUT freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define FORd(i, a, b) for(int i = (b) - 1; i >= a; --i)
#define trav(a, x) for(auto& a : x)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end() 
#define endl '\n'
const int MOD = 1000000007;
  
int main(){
    IOS;
    // FINOUT;
    int T = 1;
    // cin >> T;
    while(T--){
        int x;
        cin >> x;
        cout << (x >= 30 ? "Yes" : "No");
    }
    return 0;
}