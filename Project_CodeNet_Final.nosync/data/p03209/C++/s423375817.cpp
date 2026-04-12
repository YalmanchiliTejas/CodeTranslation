#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

ll ans = 0;
vector<ll> v(51);
vector<ll> p(51);

void dfs(ll n, ll x){
    if(v[n] - 1 <= x){
        ans += p[n];
    }else if(v[n-1] + 2 < x){
        ans += p[n-1];
        ans += 1;
        dfs(n-1,x - v[n-1] - 2);
    }else if(v[n-1] + 2 == x){
        ans += p[n-1];
        ans += 1;
    }else if(1 < x){
        dfs(n-1,(x-1));
    }
}

int main()
{
    ll n,x;
    cin >> n >> x;
    v[0] = 1;
    p[0] = 1;
    for(int i = 1; i <= 50; i++){
        v[i] = v[i-1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }
    dfs(n,x);
    cout << ans;
}