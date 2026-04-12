#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;


int main(){
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;
    
    int ans = 0;
    for(int i = 0 ; i < n ; ++i){
        bool ok = true;
        for(int j = 0 ; j < i ; ++j){
            ok &= (a[j] <= a[i]);
        }
        ans += ok;
    }
    
    cout << ans << endl;
}
