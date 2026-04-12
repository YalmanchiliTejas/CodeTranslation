#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const ll MOD = 1000000007;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    REP(i, n){
        cin >> x[i]; y[i] = x[i];
    }
    sort(y.begin(), y.end());
    REP(i, n){
        cout << (x[i] < y[n/2] ? y[n/2] : y[n/2-1]) << endl;
    }
    return 0;
}