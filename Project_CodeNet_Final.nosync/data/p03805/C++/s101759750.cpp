#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<unordered_set<ll>> net(n);
    for(int i = 0; i < m; ++i){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        net.at(a).insert(b);
        net.at(b).insert(a);
    }

    vector<ll> v(n);
    for(int i = 0; i < n; ++i){
        v.at(i) = i;
    }

    ll ans = 0;
    do{
        bool flag = true;
        for(int i = 0; i < n - 1; ++i){
            if(net.at(v.at(i)).count(v.at(i + 1)) == 0){
                flag = false;
                continue;
            }
        }
        ans += flag;
    }while(next_permutation(v.begin() + 1, v.end()));
    cout << ans << endl;
    return 0;
}
