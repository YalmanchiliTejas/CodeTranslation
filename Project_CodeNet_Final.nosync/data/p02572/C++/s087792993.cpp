#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i, n){
        cin >> a.at(i);
        sum += a.at(i);
    }
    
    ll ans = 0;
    ll b = 1e9 + 7;
    ll c = 0;
    rep(i, n - 1){
        sum -= a.at(i);
        if(sum >= b){
            c = sum % b;
        }
        else{
            c = sum;
        }
        
        ans += a.at(i) * c;
        if(ans >= b){
            ans %= b;
        }
    }
    cout << ans << endl;
    
    return 0;
}
 
 //vector<int> a(3);
 //a.at(0);
 //a.size();
 //vector<vector<int>> a(3, vector<int>(3));
 //uint64_t sum = 0;
 //max(a, b);
 //min(a, b);
 //swap(a, b);
 //sort(vec.begin(), vec.end());  昇順
 //reverse(vec.begin(), vec.end());  降順
