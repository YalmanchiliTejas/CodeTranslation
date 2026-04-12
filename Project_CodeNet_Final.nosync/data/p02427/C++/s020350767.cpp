#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>
#include <climits>
#include <iterator>
#include <iomanip>
#include <stack>
#include <set>
#include <cstdio>
#include <bitset>
#include <functional>
#include <tuple>
#include <list>
#include <deque>
using namespace std;
typedef pair<int, int> P;

#define FOR(i, a, n) for (ll i = (ll)a; i<(ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef vector<int> VI;
int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    
    int n; cin >> n;
    for(int i=0; i<(1<<n); ++i){
        
        vector<int> S;
        for(int j=0; j<n; ++j){
            if(i & (1<<j)){
                S.push_back(j);
            }
        }
        
        cout << i << ":";
        for(int j=0; j<S.size(); ++j){
            cout << " " << S[j];
        }
        cout << endl;
    }
	return 0;
}
