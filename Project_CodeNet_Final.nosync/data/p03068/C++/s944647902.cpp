#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

#define REP(i, n) for(ll i = 0; i < n; i++)








int main(){
    ll n, k;
    string s;
    cin >> n >> s >> k;
    k--;
    REP(i, n){
        if(s[i] != s[k]){
            s[i] = '*';
        }
    }
    cout << s << endl;
}