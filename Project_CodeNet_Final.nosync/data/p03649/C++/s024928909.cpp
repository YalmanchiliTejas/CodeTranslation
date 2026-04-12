#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define enld endl //* missspell check
const ll INF = 1LL << 60;


void solve(long long N, std::vector<long long> a){
    sort(ALL(a)); reverse(ALL(a));
    vll b(N, 0), btmp(N, 0);
    ll bsum=0;
    do{
        bsum = 0;
        REP(i, N){
            btmp[i] = a[i]/ N;
            a[i] %= N;
            bsum += btmp[i];
            b[i] += btmp[i];
        }
        REP(i, N) {
            btmp[i] = bsum - btmp[i];
            a[i] += btmp[i];
        }
    }while(bsum > 0);
    ll res = 0;
    REP(i, N) res += b[i];
    cout << res << endl;

}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
