#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;

int main(){
    ll k,a,b; cin >> k >> a >> b;
    if(a>=k){
        cout << 1 << endl;
        return 0;
    }
    if(a<=b){
        cout << -1 << endl;
        return 0;
    }
    ll p=a-b;
    ll ans=1+(k-a+p-1)/p*2;
    cout << ans << endl;
}