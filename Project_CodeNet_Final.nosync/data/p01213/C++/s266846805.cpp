#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

string lcs(const string& s, const string& t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    vector<vector<int> > step(n+1, vector<int>(m+1, -1));
    for(int i=n; i>=0; --i){
        for(int j=m; j>=0; --j){
            if(i > 0 && j > 0 && s[i-1] == t[j-1] && dp[i][j] + 1 > dp[i-1][j-1]){
                dp[i-1][j-1] = dp[i][j] + 1;
                step[i-1][j-1] = 0;
            }
            if(i > 0 && dp[i][j] > dp[i-1][j]){
                dp[i-1][j] = dp[i][j];
                step[i-1][j] = 1;
            }
            if(j > 0 && dp[i][j] > dp[i][j-1]){
                dp[i][j-1] = dp[i][j];
                step[i][j-1] = 2;
            }
        }
    }

    string ret;
    int a = 0, b = 0;
    while(step[a][b] != -1){
        if(step[a][b] == 0){
            ret += s[a];
            ++ a;
            ++ b;
        }else if(step[a][b] == 1){
            ++ a;
        }else{
            ++ b;
        }
    }
    return ret;
}

int main()
{
    for(;;){
        string s;
        cin >> s;
        if(s == "#END")
            return 0;

        string ret;
        for(unsigned i=1; i<s.size(); ++i){
            string t = lcs(s.substr(0, i), s.substr(i));
            if(t.size() > ret.size())
                ret = t;
        }

        cout << ret << endl;
    }
}