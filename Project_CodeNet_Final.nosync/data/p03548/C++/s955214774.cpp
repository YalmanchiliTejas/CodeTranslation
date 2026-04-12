#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <queue>
#include <map>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
const int INF = 100000000;

int main(){
    int x , y, z;
    cin >> x >> y >> z;

    int tmp = (x - z) / (y + z);
    cout << tmp << endl;
}