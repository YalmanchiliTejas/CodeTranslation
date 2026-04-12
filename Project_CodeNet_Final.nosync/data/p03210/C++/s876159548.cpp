//=====================COMPILER OPTIMIZATION STARTS=======================
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
//======================COMPILER OPTIMIZATION ENDS=======================

//compile using : g++ -D DEB file.cpp
#ifdef DEB
    //to check from out of bounds errors
    #define _GLIBCXX_DEBUG
#endif
//=============================DEBUG PART ENDS===========================

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

ll power(ll x, ll y, ll mod = 1e9+7){
    ll res = 1;
    while(y > 0){
        if(y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x*x)% mod;
    }
    return res % mod;
}

void solve(){
    int n;  cin >> n;
    if (n == 3 || n == 5 || n == 7)
        cout << "YES\n";
    else 
        cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);	cout.tie(0);

    int test = 1;
    // cin >> test;
    while(test--)
        solve();
    return 0;
}