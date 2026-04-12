// ABC177C.cpp :

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);++i)

const int mod = 1'000'000'007;
int main()
{
    int n;
    cin >> n;
    vector<ll>a(n);
    ll sum = 0;
    ll ans = 0;
    rep(i,n){
        cin >> a.at(i);
        ans = (ans + (a.at(i) * sum)) % mod;
        sum = (sum+a.at(i)) % mod;
    }
    cout << ans << endl;
}
