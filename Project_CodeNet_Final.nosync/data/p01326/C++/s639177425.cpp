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

int main()
{
    const int MOD = 1000000;

    string pattern[] = {"0xxxxxxx",
                        "110yyyyx10xxxxxx",
                        "1110yyyy10yxxxxx10xxxxxx",
                        "11110yyy10yyxxxx10xxxxxx10xxxxxx"};

    vector<bitset<32> > p0(4), p1(4), px(4), py(4);
    for(int i=0; i<4; ++i){
        for(int j=0; j<8*(i+1); ++j){
            if(pattern[i][j] == '0')
                p0[i][j] = true;
            if(pattern[i][j] == '1')
                p1[i][j] = true;
            if(pattern[i][j] == 'x')
                px[i][j] = true;
            if(pattern[i][j] == 'y')
                py[i][j] = true;
        }
    }

    for(;;){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        vector<bitset<32> > b0(n+1), b1(n+1), bx(n+1);
        for(int i=1; i<=n; ++i){
            for(int j=0; j<8; ++j){
                char c;
                cin >> c;
                if(c == '0')
                    b0[i][j] = true;
                if(c == '1')
                    b1[i][j] = true;
                if(c == 'x')
                    bx[i][j] = true;
            }
        }

        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; ++i){
            bitset<32> a0, a1, ax;
            for(int j=0; j<min(i,4); ++j){
                a0 <<= 8;
                a1 <<= 8;
                ax <<= 8;
                a0 |= b0[i-j];
                a1 |= b1[i-j];
                ax |= bx[i-j];
                if((a1 & p0[j]).any() || (a0 & p1[j]).any())
                    continue;

                int numX = 1 << (ax & px[j]).count();
                int numY = 1 << (ax & py[j]).count();
                if(j > 0 && (a1 & py[j]).none())
                    -- numY;
                dp[i] += (dp[i-j-1] * numX) % MOD * numY;
                dp[i] %= MOD;
            }
        }

        cout << dp[n] << endl;
    }
}