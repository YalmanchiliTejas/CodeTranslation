#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <random>
#include <cassert>
#include <numeric>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;

ll y[10000005];

int main() {
    int h, w; cin >> h >> w;
    char a[h][w];
    rep(i,h) rep(j,w) cin >> a[i][j];

    vector<int> haji(h),owa(h);
    rep(i,h){
        rep(j,w){
            if(a[i][j] == '#') {
                haji[i] = j;
                break;
            }
        }
        for(int j = w-1; j >= 0;j--){
            if(a[i][j] == '#'){
                owa[i] = j;
                break;
            }
        }
    }
    rep(i,h-1){
        if(owa[i] != haji[i+1]){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
}
