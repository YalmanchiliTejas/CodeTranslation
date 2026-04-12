#include <bits/stdc++.h>
#define MAX 100009
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<long long> vl;

multiset<ll> s;
vector<ll> v;

int main() {
    ll n;
    cin >> n;

    v.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
        
    for(int i = n-1; i >= 0; --i) {
        s.insert(v[i]);
        auto it = s.upper_bound(v[i]);

        if(it != s.end())
            s.erase(it);
    }

    cout << s.size() << endl;
    return 0;
}