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
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define Yes(condition) if(condition){ cout << "Yes" << '\n'; }else{ cout << "No" << '\n'; }
#define YES(condition) if(condition){ cout << "YES" << '\n'; }else{ cout << "NO" << '\n'; }
#define yes(condition) if(condition){ cout << "yes" << '\n'; }else{ cout << "no" << '\n'; }





int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    
    if(k <= a){
        cout << 1 << endl;
        return 0;
    }
    
    if(a > b){
        cout << (((k - a) % (a - b) != 0)? k / (a - b) * 2 + 1 : (k - a) / (a - b) * 2 + 1) << endl;
    }
    else{
        cout << -1 << endl;
    }
}
