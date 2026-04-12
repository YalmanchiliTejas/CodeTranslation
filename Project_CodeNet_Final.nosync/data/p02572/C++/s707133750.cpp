/*Allah Vorosha*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define n_p next_permutation
#define p_p prev_permutation
#define in insert
#define rev reverse
#define pf push_front
#define pob pop_back
#define uniq(v)			v.resize(distance(v.begin(),unique(v.begin(),v.end())))
#define all(x) (x).begin(),(x).end()
#define pof pop_front
#define ios ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define scn scanf
#define prt printf
#define rep(i, a, n) for(int i = a; i < n; i++)
#define mod 1000000007
#define yes cout << "Yes\n"
#define no cout << "No\n";
#define take for(auto &it : a) cin >> it;
#define out cout << a << "\n";
#define l_b lower_bound
#define u_b upper_bound
#define Max 100005
template<typename T> T mymax(T x, T y) {
    return (x > y ? x : y);
}

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    take;
    ll sum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (sum * a[i]);
        sum += a[i];
        sum %= mod;
        ans %= mod;
    }
    cout << ans << '\n';
    return;
}

int main() {
    /*int tc;
    cin >> tc;
    while(tc-- > 0)*/
    solve();
    return 0;
}
