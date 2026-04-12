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

string s, t;
int n, m;

vector<vector<int> > memo;
vector<vector<int> > step;

int solve(int a, int b)
{
    if(a == n || b == m)
        return 0;
    if(memo[a][b] != -1)
        return memo[a][b];

    int ret = 0;
    if(s[a] == t[b]){
        ret = solve(a+1, b+1) + 1;
        step[a][b] = 0;
    }

    int x = solve(a+1, b);
    if(x > ret){
        ret = x;
        step[a][b] = 1;
    }

    int y = solve(a, b+1);
    if(y > ret){
        ret = y;
        step[a][b] = 2;
    }

    return memo[a][b] = ret;
}

int main()
{
    for(;;){
        string input;
        cin >> input;
        if(input == "#END")
            return 0;

        string ret;
        for(unsigned i=1; i<input.size(); ++i){
            s = input.substr(0, i);
            t = input.substr(i);
            n = i;
            m = input.size() - i;

            memo.assign(n+1, vector<int>(m+1, -1));
            step.assign(n+1, vector<int>(m+1, -1));
            solve(0, 0);

            string u;
            int a = 0;
            int b = 0;
            while(step[a][b] != -1){
                if(step[a][b] == 0){
                    u += s[a];
                    ++ a;
                    ++ b;
                }else if(step[a][b] == 1){
                    ++ a;
                }else{
                    ++ b;
                }
            }

            if(u.size() > ret.size())
                ret = u;
        }

        cout << ret << endl;
    }
}