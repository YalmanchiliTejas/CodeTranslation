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
const long long INF = 1LL << 61;

int MOD = 1000000007;


int main(){
    std::ios_base::sync_with_stdio(false);

    int n,k; cin >> n;
    string s; cin >> s;
    cin >> k;
    char x = s[k-1];
    string ans = "";
    rep(i, s.size()){
        if(s[i]!=x){
            ans+='*';
        } else {
            ans+=s[i];
        }
    }

    cout << ans << endl;

    
    return 0;
}
