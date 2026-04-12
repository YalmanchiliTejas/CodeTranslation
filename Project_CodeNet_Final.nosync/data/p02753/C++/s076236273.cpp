#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <queue>
using _loop_int = int;
#define REP(i,n) for(_loop_int i=0; i<(_loop_int)(n); i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a); i<(_loop_int)(b); i++)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1; i>=(_loop_int)(a); i--)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int main(){
    string s, ans;
    cin >> s;
    if(s[0] == s[1] & s[1] == s[2]){
        ans = "No";
    } else {
        ans = "Yes";
    }
    cout << ans << endl;

    return 0;
}
