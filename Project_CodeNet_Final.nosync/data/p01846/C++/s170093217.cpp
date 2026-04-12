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
#define pi M_PI
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
    string s;
    while (cin >> s && s != "#"){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        VVI f;
        VI r;
        REP(i,s.length()){
            if (s[i] == 'b'){
                r.push_back(1);
            }else if (s[i] > '0' && s[i] <= '9'){
                REP(x,s[i]-'0') r.push_back(0);
            }else{
                f.push_back(r);
                r.clear();
            }
        }
        f.push_back(r);
        int h = f.size(), w = f[0].size();
        f[a-1][b-1] = 0;
        f[c-1][d-1] = 1;
        string ans;
        REP(i,h){
            int x = 0;
            REP(j,w){
                if (f[i][j]){
                    if (x > 0) ans += x + '0';
                    ans += 'b';
                    x = 0;
                }else{
                    x++;
                }
            }
            if (x > 0) ans += x + '0';
            if (i < h-1) ans += '/';
        }
        cout << ans << endl;
    }
    return 0;
}