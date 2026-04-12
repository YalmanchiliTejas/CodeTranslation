#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll k, a, b; cin >> k >> a >> b;
    if(a-b <= 0){
        if(a < k){
            cout << -1 << endl;
        }else{
            cout << 1 << endl;
        }
        return 0;
    }
    ll ans = (k-a+(a-b-1))/(a-b);
    cout << 2*ans+1 << endl;
}