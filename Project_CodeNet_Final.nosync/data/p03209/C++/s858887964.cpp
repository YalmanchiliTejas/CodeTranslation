#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) int((x).size())
#define OUT(x) cout << (x) << endl
typedef long long ll;
typedef vector<int> V;
typedef vector<vector<int>> VV;
typedef pair<int, int> P;
typedef map<string, int> M;
typedef unordered_map<int, int> HM;
typedef set<int> S;
typedef queue<int> Q;

ll modpow(ll a, ll p)
{
    if (p == 0)
    {
        return 1;
    }
    if (p % 2 == 0)
    {
        ll half = modpow(a, p / 2);
        return half * half;
    }
    else
    {
        return a * modpow(a, p - 1);
    }
}

ll ans = 0;
void solve(ll n, ll x){
    ll a = modpow(2, n+1) - 3;
    ll p = modpow(2, n) - 1;
    if(n == 0){
        ans++;
        return;
    }
    if(x <= 1){
        return;
    }
    else if(x <= a+1) solve(n-1, x-1);
    else if(x == a+2){
        ans += p+1;
        return;
    } 
    else if(x <= a*2+2){
        ans += p+1;
        solve(n-1, x-a-2);
    }
    else if(x == a*2+3){
        ans += p*2 +1;
        return;
    }
    return;
}

int main(){
    ll n,x; cin>>n>>x;
    solve(n, x);
    OUT(ans);
}