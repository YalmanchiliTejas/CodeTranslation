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
    string ans = "NO\n";
    if(n == 3) ans = "YES\n";
    if(n == 5) ans = "YES\n";
    if(n == 7) ans = "YES\n";
    cout << ans;
    return 0;
}