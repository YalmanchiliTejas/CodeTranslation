#include <bits/stdc++.h>//復習必須
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
int main (){ 
    ll n ;
    cin >> n ;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    vector<int> s;
    s.assign(x.begin(), x.end());
    sort(s.begin(), s.end(), less<int>());
 
    rep(i, n) {
    int l = s[n / 2 - 1];
    int r = s[n / 2];
    int mid = x[i] <= l ? r : l;
    cout << mid << endl;
  }

}
    

 
