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
    vector<int> num(26, 100000);
    int n; cin >> n;
    REP(i, n){
        string s; cin >> s;
        vector<int> cnt(26, 0);
        REP(j, s.length()){
            ++cnt[s[j] - 'a'];
        }
        REP(j, 26) num[j] = min(num[j], cnt[j]);
    }
    
    REP(i, 26){
        REP(j, num[i]) cout << char('a' + i);
    }
    cout << "\n";
    return 0;
}