#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
#include <array>
#include <numeric>
#include <regex>
#include <bitset>
#include <deque>

using namespace std;
typedef long long ll;
typedef pair<int, int> p_ii;

const int INF = 1e9;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;

ll a[51], p[51];

ll dfs(ll n, ll x){
    if(n==0) return 1LL;
    if(x==1) return 0LL;

    if(x>=2 && x<=a[n-1]+1)return dfs(n-1, x-1);
    else if(x==a[n-1]+2)return p[n-1]+1;
    else if(x>=a[n-1]+3 && x<=2*a[n-1]+2)return dfs(n-1, x-a[n-1]-2)+p[n-1]+1;
    else if(x==2*a[n-1]+3)return p[n];
}

int main() {
    ll N, X; cin>>N>>X;
    
    a[0]=1, p[0]=1;
    for (int i = 0; i < 50; i++) {
        a[i+1]=2*a[i]+3;
        p[i+1]=2*p[i]+1;
    }

    cout<<dfs(N, X)<<endl;

    return 0;
}