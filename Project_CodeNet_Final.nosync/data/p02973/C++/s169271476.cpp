#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> A(N);
    Rep (i, N) {
        cin >> A[i];
    }

    multiset<ll> color;
    Rep (i, N) {
        auto itr = color.upper_bound(-A[i]);
        // cout << *itr << "\n";
        if (itr != color.end()) {
            color.erase(itr);
        }
        // color.erase(*itr);
        color.insert(-A[i]);
        // for (auto itr = color.begin(); itr != color.end(); itr++) {
        //     cout << -*itr << " ";
        // }
        // cout << "\n";
    }
    
    // for (auto itr = color.begin(); itr != color.end(); itr++) {
    //     cout << -*itr << " ";
    // }
    // cout << "\n";

    cout << color.size() << "\n";
}
