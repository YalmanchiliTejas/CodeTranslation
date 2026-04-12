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
    int N;
    cin >> N;
    vector<ll> a(N);
    for(auto& x: a) cin >> x;

    Vvec<ll> dp(N+1, vector<ll>(N+1));
    for(int l=N-1; l>=0; l--){
        for(int i=0; i<=l; i++){
            int j = l - i;
            // cout << i << " " << j << endl;
            if(l%2==0){
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j+1] + a[N-j-1]);
            }
            else{
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j+1] - a[N-j-1]);
            }
        }
    }

    cout << dp[0][0] << endl;
    // for(int i=0; i<=N; i++) debug(dp[i]);
}