#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if(k==0){
        ans = n*n;
        cout << ans << endl;
        return 0;
    }
    for(int i = k+1; i < n+1; i++){
        ans += (n/i)*(i-k);
        int tmp = n%i;
        if(tmp>=k){ans += tmp-k+1;}
    }
    cout << ans << endl;
    return 0;

}
