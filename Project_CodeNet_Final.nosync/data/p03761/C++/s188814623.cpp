#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi acos(-1.0)

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int hash_min[256] = {};
    fill(hash_min, hash_min + 256, 50);
    REP(i, n){
        string s;
        cin >> s;
        int hash_buf[256] = {};
        REP(j, s.size()){
            hash_buf[(int)s[j]]++;
        }
        FOR(j, 'a', 'z'){
            hash_min[j] = min(hash_min[j], hash_buf[j]);
        }
    }

    string ans;
    FOR(j, 'a', 'z'){
        ans += string(hash_min[j], (char)j);
    }
    cout << ans << "\n";
    return 0;
}
