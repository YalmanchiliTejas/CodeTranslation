#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <bitset>
#include <queue>
#include <unordered_set>

using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
#define rep(i, n) for(int i = 0;i < n;i++)
const int INF = 1LL << 30;

int MOD = 1000000007;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n; 
    std::vector<ll> a(n); rep(i,n) cin >> a[i];

    // 昇順
    std::deque<ll> dq;

    rep(i,n){
        int index = std::lower_bound(dq.begin(), dq.end(), a[i]) - dq.begin();

        if(index==0){
            dq.push_front(a[i]);
        } else {
            dq[index-1] = a[i];
        }
    }

    cout << dq.size() << endl;

    return 0;
}