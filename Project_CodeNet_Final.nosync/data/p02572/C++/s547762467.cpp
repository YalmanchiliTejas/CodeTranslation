#include <bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lp(i, n) for(int i = 0; i < n; i++)
#define rlp(i, n) for(int i = n-1; i >= 0; i--)
#define loop(i, a, b) for(int i = a; i <= b; i++)
#define rloop(i, a, b) for(int i = a; i >= b; i--)
#define mem(a, val) memset(a, val, sizeof a);
#define all(v) v.begin(),v.end()
#define ll long long
#define ld long double
#define mp_ make_pair
#define sz(s) (int)s.size()
#define pb push_back
const int MAX = 1e5 + 5;
const int inf = 1e9+1;
const ll OO = 1e18;
const ll mod = 1e9 + 7;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

ll MOD(ll a, ll b){
    return ((a % b) + b) % b;
}

int main(){


    int n;
    cin>> n;
    vector<ll> v(n);

    ll sum = 0, ans = 0;
    lp(i, n) cin>> v[i], sum += v[i];

    lp(i, n-1){
        sum -= v[i];
        ans = MOD(ans + MOD(MOD(sum, mod) * v[i], mod), mod);
    }
    cout<< ans;
    return 0;
}
