#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i=0; i<n; i++)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define reprs(i, s, e) for(int i=e-1; i>=s; i--)

ll n, x;
ll nlayer[51], npatty[51];

ll dfs(ll n, ll x){
    if(n == 0) return 1;

    ll center = (nlayer[n] + 1)/2;

    if(x == 1) return 0;
    else if(x < center) return dfs(n-1, x-1);
    else if(x == center) return npatty[n-1] + 1;
    else return dfs(n-1, x-center) + npatty[n-1] + 1; 
}


int main(){

    cin >> n >> x;

    nlayer[0] = 1;
    npatty[0] = 1;
    reps(i, 1, n+1){
        nlayer[i] = 2*nlayer[i-1] + 3;
        npatty[i] = 2*npatty[i-1] + 1;
        // cout << nlayer[i] << " " << npatty[i] << endl;
    }


    cout << dfs(n, x);

    return 0;
}