#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

void Main(){
    ll n, s, i, j;
    cin >> n >> s;
    vector<ll> a(n);
    for (i=0; i<n; i++){
        cin >> a.at(i);
    }
    vector<vector<ll>> t(n, vector<ll>(s+1));
    for (ll i=0; i<n; i++){
        t[i][0] = i+2;        
    }
    if (a[0] <= s){
        t[0][a[0]] = 1;
    }
    for (i=1; i<n; i++){
        for (j=1; j<s+1; j++){
            t[i][j] = t[i-1][j];
            if (j - a[i] >= 0){
                t[i][j] += t[i-1][j-a[i]];
                t[i][j] %= 998244353;
            }
        }
    }
    ll sum = 0;
    for (vector<ll> v: t){
        // for (ll x : v){
        //     cout << x;
        // }
        // cout << endl;
        sum += v[s];
        sum = sum % 998244353;
    }
    cout << sum;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
    Main();
}