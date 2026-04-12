#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
    #include "/home/v-o_o-v/deb.h"
    #define deb(x...)cerr << "[" << #x << "] = [";_print(x);
#else
    #define deb(x...)
#endif

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int h[n];
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        cin >> h[i];
        if(v.empty())v.pb(h[i]);
        else if(v.back() <= h[i])v.pb(h[i]);
    }
    cout << v.size() << '\n';
    return 0;
}
// Write Here
