#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), ind(N);
    for(auto& x: A) cin >> x;
    
    vector<ll> s(N);
    s[0] = A[0];
    for(int i=1; i<N; i++){
        if(i%2==0) s[i] = s[i-2] + A[i];
        else s[i] = s[i-1];
    }
    vector<ll> dp(N);
    dp[0] = 0;
    dp[1] = max(A[0], A[1]);
    for(int i=2; i<N; i++){
        if(i%2==0) dp[i] = max(dp[i-1], dp[i-2] + A[i]);
        else dp[i] = max(s[i-1], dp[i-2] + A[i]);
    }
    
    cout << dp[N-1] << endl;
    // debug(dp);
}