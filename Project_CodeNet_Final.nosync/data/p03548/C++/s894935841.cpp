#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    
    ll ans=0;
    ans=(X-Z)/(Y+Z);
    cout << ans << endl;
    return 0;
}