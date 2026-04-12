#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;  // INFの値は1152921504606846976

int main()
{
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    for(int i = k+1; i <= n; i++){
        ans += (((n/i) * (i-k)) + max((n%i+1-k),(ll)0));
    }
    if(k == 0) ans -= n;
    cout <<ans;
}
