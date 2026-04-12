#include <iostream>
#include <vector>

#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <unordered_set>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <cstring>
#include <stack>
#include <queue>
#include <numeric>
 
 
//#include <bits/stdc++.h>
typedef long long ll;
#define nl "\n"
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

/*
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


*/

int main(){
    int n ;  cin>>n;
    if( n>= 30 ) cout<<"Yes";
    else cout<<"No";
}
