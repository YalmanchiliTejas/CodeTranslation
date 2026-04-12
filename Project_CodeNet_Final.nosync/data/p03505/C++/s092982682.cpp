#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
typedef long long ll;
ll k, a, b;

int main(){
    ios::sync_with_stdio(false);
    cin >> k >> a >> b;
    ll tmp = a - b, ans = 0;
    if(k > a && tmp < 0){
        ans = -1;
    }
    else if(k <= a){
        ans = 1;
    }
    else if(tmp != 0){
        ans = (k - a)/tmp;
        if(ans * tmp == (k - a)){
            ans = ans*2 + 1;
        }
        else ans = (ans + 1)*2 + 1;
    }
    else ans = -1;
    cout << ans << "\n";
    return 0;
}
