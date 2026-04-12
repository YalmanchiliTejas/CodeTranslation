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

ll solve(string str, ll num){
    ll start = 0;
    while(start < str.length()){
        if(str[start] != '0')
            break;
        start++;
    }
    str = str.substr(start, str.length()-start);


    if(str.length()==0) return 0;
    if(num == 0) return 0;
    ll N = str.length(), res=0;
    if(num == 1){
        REP(i, N){
            if(i == 0) res += (ll) (str[i] - '1')+1;
            else res += 9;
        }
        return res;
    }
    if(num == 2){
        res = solve(str.substr(1, N-1), num-1);
        res +=  (str[0]-'1') * (N-1) * 9;
        res += (N-1)*(N-2) / 2 * 81;
        return res;
    }
    if(num == 3){
        res = solve(str.substr(1, N-1), num-1);
        res += (str[0]-'1') * (N-1)*(N-2) / 2 * 81;
        res += (N-1)*(N-2)*(N-3)/6 * 9*9*9;
        return res;
    }
    return 0;
}

int main(){
    string S;
    cin >>S;
    long long K;
    cin>>K;
    ll ans = solve(S, K);
    cout<<ans<<endl;

    return 0;
}
