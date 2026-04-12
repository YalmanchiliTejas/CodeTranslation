#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;
//cout <<  << endl;
typedef long long int ll;
typedef long double ld;

using Graph = vector<vector<ll>>;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

#define MAX_N 2010

const long long INF = 1LL << 60;

//境界値に注意！！！
int main() {
    ll x,y,z,ans=0;
    cin >> x >> y >> z;
    ll s=y+z;
    while(ans*s<=x-z){
        ans++;
    }
    cout << ans-1 << endl;
}
