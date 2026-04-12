#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void)
{
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> p(0), a(m), b(m); 

    for(ll i = 0; i < m; i++) {
        cin >> a.at(i) >> b.at(i);
    }

    for(ll i = 1; i <= n; i++) {
        p.push_back(i);
    }

    do {
        if(p.at(0) == 2)
            break;
        
        bool exist = true;
        for(ll i = 0; i < n - 1; i++) {
            bool root_exist = false;
            for(ll j = 0; j < m; j++) {
                if( ( p.at(i) == a.at(j) && p.at(i + 1) == b.at(j) ) || ( p.at(i) == b.at(j) && p.at(i + 1) == a.at(j) ))
                    root_exist = true;
            }

            if(root_exist == false)
                exist = false;
        }

        if(exist)
            ans++;

    } while ( next_permutation(p.begin(), p.end()) );

    cout << ans;
    return 0;
}