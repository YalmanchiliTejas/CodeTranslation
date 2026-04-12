#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

signed main(){

    int n; cin >> n;
    list<int> L;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(i % 2 == 0) L.push_back(a);
        else L.push_front(a);
    }

    if(n % 2 == 1) reverse(L.begin(), L.end());

    for(auto x : L) cout << x << " ";
    cout << endl;
    return 0;
}