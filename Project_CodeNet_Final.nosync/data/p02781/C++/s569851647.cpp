#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> bool chmax(T& a, const T& b){ if(a < b){ a = b; return 1; } return 0; }

ll pow(ll a, ll b){
    ll ans = 1;
    while(b--) ans *= a;
    return ans;
}
ll comb(ll n, ll r){
    ll ans = 1;
    for(ll i = 0; i < r; i++){
        ans *= n - i;
        ans /= i + 1;
    }
    return ans;
}
ll solve(string n, ll k){
    ll size = n.size();
    if(size < k) return 0;
    if(k == 0) return 1;
    ll ans = 0;
    // n より桁数が少ないもの
    if(size > k) ans += comb(size - 1, k) * pow(9LL, k);
    // n と桁数が同じで、最上位が n[0] より小さいもの
    ans += (n[0] - '1') * comb(size - 1, k - 1) * pow(9LL, k - 1);
    // n と桁数が同じで、最上位が n[0] と同じもの
    ll at = 1;
    while(n[at] == '0') at++;
    ans += solve(n.substr(at, size - at), k - 1);
    return ans;
}
int main(){
    string n;
    ll k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
}