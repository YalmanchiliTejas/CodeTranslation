#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)





int main() {
    string s;
    cin >> s;
    
    while(s != "#"){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;
        
        vector<string> x(9);
        int y = 0;
        REP(i, s.size()){
            if(s[i] == 'b'){
                x[y] += 'b';
            }
            else if(s[i] == '/'){
                y++;
            }
            else{
                REP(j, s[i] - '0'){
                    x[y] += '.';
                }
            }
        }
        
        x[a][b] = '.';
        x[c][d] = 'b';
        
        string ans;
        REP(i, y + 1){
            for(ll j = 0; j < x[i].size();){
                if(x[i][j] == '.'){
                    ll c = 0;
                    for(; j < x[i].size() && x[i][j] == '.'; j++){
                        c++;
                    }
                    ans += (c + '0');
                }
                else{
                    ans += 'b';
                    j++;
                }
            }
            if(i < y){
                ans += '/';
            }
        }
        cout << ans << '\n';
        
        cin >> s;
    }
}
