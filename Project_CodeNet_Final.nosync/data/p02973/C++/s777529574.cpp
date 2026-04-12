#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    multiset<ll> x;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        auto it = x.lower_bound(a);
        if(it != x.begin()){
            x.erase(--it);
        }
        x.insert(a);
    }
    cout << x.size() << endl;
    return 0;
}
