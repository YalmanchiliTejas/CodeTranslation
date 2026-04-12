
#include <iostream>
// #include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

#include <stack>
#include <queue>
// #include <deque>
#include <set>
#include <map>
// #include <string>
// #include <unordered_set>
// #include <unordered_map>

#include <tuple>
// #include <cmath>
// #include <numeric>

using namespace std;


typedef long long ll;
typedef pair<long,long> pll;
typedef pair<int,int> pii;
typedef pair<int,long> pil;
typedef pair<long,int> pli;
typedef pair<long long, long long> pllll;
typedef pair<long long, int> plli;
typedef pair<int,long long> pill;
typedef vector<vector<long long>> vvll;
typedef vector<vector<long>> vvl;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;

#define emplace_back pb
const char el = '\n';

ll dp[200001][2]; //dp[i][bool] = maximum of choosing floor(i/2) non-adjacent,
//given whether we include the last one (bool=0 means we omit, 1 means we include)
ll oddpref[200001]; //oddpref[5] = a[1]+a[3]+a[5]; oddpref[even] is undefined
ll a[200001]; //the array; may contain NEGATIVE

/*
Edge cases:

does negative affect anything??

*/

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin>>n;


    ll oddtemp = 0;
    for (int i=1; i<=n; ++i) {
        cin>>a[i];
        if (i%2 == 1) {
            oddtemp += a[i];
            oddpref[i] = oddtemp;
        }
    }


    dp[1][0]=0;
    // dp[1][1] = 0; //TECHNICALLY UNDEFINED; MAKE SURE WE DON'T USE IT;

    for (int i = 2; i<=n; ++i) {
        if (i%2==1) {
            //doing an even to odd transition; use SAME # of terms

            ll excludecand = max(dp[i-1][0],dp[i-1][1]);
            ll includecand = a[i] + max(dp[i-2][0],dp[i-2][1]);

            dp[i][0] = excludecand;
            dp[i][1] = includecand;
        } else {

            //doing an odd to even transition; can get 1 extra term;
            //if we EXCLUDE a[i], say a[6], then we must include 3 from a[1:5];
            //this forces us to use 1,3,5;
            //if we INCLUDE a[6], then we do 2 from the first 5, where we don't include
            //the last term;
            ll excludecand = oddpref[i-1];
            ll includecand = a[i] + dp[i-1][0];

            dp[i][1] = includecand;
            dp[i][0] = excludecand;
        }

        // cout<<"max including a["<<i<<"]="<<a[i]<<" equals "<<dp[i][1]<<";  ";
        // cout<<"without equals "<<dp[i][0]<<el;

    }

    cout<< max(dp[n][0],dp[n][1]) << el;

}