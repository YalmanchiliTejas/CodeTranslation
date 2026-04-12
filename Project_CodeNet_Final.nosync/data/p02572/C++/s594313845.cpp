#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using V = vector<int>;

int main(int argc, char const *argv[])
{
    long long int n, a; cin >> n;
    long long int sum = 0, sq_sum = 0;
    int mod = 1000000007;
    rep(i,n){
        cin >> a; sum += a; sq_sum += a*a;
        sum %= mod; sq_sum %= mod;
    }
  	long long int ans = sum * sum % mod - sq_sum + mod;
    ans *= (mod+1)/2;
    ans %= mod;
    cout << ans << endl;
    return 0;
}