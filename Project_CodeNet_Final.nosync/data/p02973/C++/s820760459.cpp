#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;

int main () {
    ll n;
    cin >> n;
    multiset <ll> se;

    vector <ll> vec (n);
    for(ll i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    for(ll i = 0; i < n; i++)
    {
        ll cur = vec[i];
        auto itr = se.lower_bound(cur);

        if(itr != se.begin())
        {
            se.erase(--itr);
        }
        se.insert(cur);
    }
    cout << se.size() << endl;
    return  0 ;
}
