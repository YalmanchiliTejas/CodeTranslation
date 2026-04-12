#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i=0;i<(n);++i)

template<class T> inline bool chmax(T& a,T b){if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if (a > b) {a = b;return 1;}return 0;}

int main(){
    int X;cin >> X;

    if (X>=30) {
        cout<< "Yes"<< endl;
    } else {
        cout<< "No"<< endl;
    }
    return 0;
}