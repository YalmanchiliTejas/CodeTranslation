#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>

using namespace std;
#define int long long int
const int INF = 1001001001001001LL;
const int MOD = 1000000007;

signed main(){
    
    while(1){
        string s; cin >> s;
        int num = 0;
        if(s == "#") break;
        int a, b, c, d; cin >> a >> b >> c >> d;
        string str = "";
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i] == 'b') str = str + "b";
            else if(s[i] != '/'){
                int val = stol(s.substr(i, 1));
                for(int i = 0; i < val; i++) str = str + ".";
            }else if(num == 0){
                num = (int)str.size();
            }
        }

        str[(a - 1) * num + (b - 1)] = '.';
        str[(c - 1) * num + (d - 1)] = 'b';

        string ans = "";
        for(int i = 0; i < (int)str.size(); i += num){
            string t = str.substr(i, num);
            t = t + "b";
            int val = 0;
            for(int j = 0; j < (int)t.size(); j++){
                if(t[j] == 'b'){
                    if(val != 0) ans = ans + to_string(val);
                    val = 0;
                    if(j != (int)t.size() - 1) ans = ans + "b";
                }else{
                    val++;
                }
            }

            ans = ans + "/";
        }

        cout << ans.substr(0, (int)ans.size() - 1) << endl;

    }
    return 0;
}


