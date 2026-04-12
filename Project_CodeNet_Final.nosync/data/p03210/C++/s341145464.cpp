#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)(1e9+7)
#define EPS 1e-9

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;

    cin >> n;

    if(n == 7 || n == 5 || n == 3)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;


    return 0;
}