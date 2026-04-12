#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;

void printvec(vector<long> v) {
    REP(i,v.size()-1) {
        cout << v[i] << " ";
    }
    cout << v.back() << endl;
}

int main() {
    int n;
    long a;
    vector<long> as;
    cin >> n;
    REP(i,n) {
        cin >> a;
        as.push_back(a);
    }
    
    vector<long> ans;
    
    for (int i = n - 1; i >= 0; i-=2) {
        ans.push_back(as[i]);
    }
    for (int i = n % 2; i < n; i+=2) {
        ans.push_back(as[i]);
    }
    
    printvec(ans);
}
