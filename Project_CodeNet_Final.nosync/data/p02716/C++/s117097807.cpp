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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

void solve(long long N, std::vector<long long> A){
    vector<vll> dp(N+1, vll(3, -INF));
    dp[1][1] = 0; dp[1][2] = A[0];
    dp[2][0] = 0; dp[2][1] = max(A[0], A[1]); dp[2][2] = -INF;
    for(ll i = 3; i <= N; i++){
        for(ll j = (i/2)-1; j <= (i+1)/2; j++){
            if(j-1-((i-2)/2-1) >= 0 && j > 0)
                dp[i][j - ((i/2)-1)] = max(dp[i-1][j - ((i-1)/2-1)], dp[i-2][j-1-((i-2)/2-1)] + A[i-1]);
            else 
                dp[i][j - ((i/2)-1)] = dp[i-1][j - ((i-1)/2-1)];
        }
    }
    cout<< dp[N][1] <<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
