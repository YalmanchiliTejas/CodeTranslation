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


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e17;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(int i = 0; i < n; i++)



int main() {
    ll n, x[200000], a[200000];
    
    cin >> n;
    REP(i, n){
        scanf("%lld", &x[i]);
        a[i] = x[i];
    }
    
    sort(a, a + n);
    ll c = a[(n - 1) / 2];
    
    REP(i, n){
        if(x[i] <= c){
            printf("%lld\n", a[(n - 1) / 2 + 1]);
        }
        else{
            printf("%lld\n", a[(n - 1) / 2]);
        }
    }
}