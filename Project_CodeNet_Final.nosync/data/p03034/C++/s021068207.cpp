#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

const ll MOD = 1000000007;
const long double EPS = 1e-10;
const int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> s(n);
    for(int i=0;i<n;++i){
        cin >> s[i];
    }

    ll score = 0LL;
    for(int c=1;c<n/2;++c) {
        ll tmp_score = 0LL;
        if((n-1) % c) {
            for(int x=0;n-1-c*x>=c;++x) {
                tmp_score += s[c*x] + s[n-1-c*x];
                score = max(score, tmp_score);
            }
        } else {
            for(int x=0;c*x<n-1-c*x;++x) {
                tmp_score += s[c*x] + s[n-1-c*x];
                score = max(score, tmp_score);
            }
        }
        
    }

    cout << score << endl;
}
