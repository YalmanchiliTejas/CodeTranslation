#include <bits/stdc++.h>
#include <iostream>

//  fastIO
#define endl "\n"

// types
#define ll long long

// vectors 
#define vec_i std::vec<int>

// vectors operations
#define pb push_back
#define eb emplace_back
#define size(a) ((int)(a.size()))

// useful math
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a) >= (0)? (a):(-a)) 


ll gcd(ll a, ll b) {
    while(b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }   
    return a;
}

using namespace std;

int main() {
    string s;
    int n,k;

    cin >> n;
    cin >> s;
    cin >> k;

    for(int i = 0; i < n; i++) {
        if((s[i] != s[k-1]) ) cout << '*';
        else cout << s[i];
    }
    cout << endl;
}

