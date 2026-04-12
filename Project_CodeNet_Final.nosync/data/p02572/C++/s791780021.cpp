#include <bits/stdc++.h>

#define endl '\n'
#define PB push_back
#define PF push_front
#define MP make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 14;

int main(){
    ios_base::sync_with_stdio(false); //cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for (auto& a : v) {
        cin >> a;
        sum += a;
    }

    ll ans = 0;
    for (size_t i = 0; i < v.size(); i++) {
        sum -= v[i];
        ans = (ans + ((v[i] % INF) * (sum % INF)) % INF) % INF;
    }
    cout << ans;
    return 0;
} 
