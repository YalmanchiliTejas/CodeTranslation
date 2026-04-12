#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,a;
    cin >>n;
    multiset<ll> ms;
    for(int i=0;i<n;i++){
        cin>>a;
        auto itr=ms.lower_bound(a);
        if(itr!=ms.begin()){
            itr--;
            ms.erase(itr);
        }
        ms.insert(a);
    }
    cout << (ms.size()) <<endl;
    return 0;
}
