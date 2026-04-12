#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <string>
using namespace std;
//cout <<  << endl;
typedef long long int ll;
typedef long double ld;

bool vfind(vector<ll> v, ll num) {
    auto itr = find(v.begin(), v.end(), num);
    size_t index = distance( v.begin(), itr );
    if (index != v.size()) { // 発見できたとき
        return true;
    }
    else { // 発見できなかったとき
        return false;
    }
}

int main(){
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    ll x=a[0]*100+a[1]*10+a[2];
    if (x%4==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
