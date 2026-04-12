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
    for(;;){
        vector<int> n(3, 0);
        for(int i=0; i<6; ++i){
            int a;
            cin >> a;
            n[i%3] += a;
        }
        if(n[0] + n[1] + n[2] == 0)
            return 0;

        int ret = 0;
        for(int i=0; i<3; ++i){
            if(n[i] > 0){
                -- n[i];
                ret += n[i] / 3;
                n[i] %= 3;
                ++ n[i];
            }
        }

        sort(n.begin(), n.end());
        vector<bitset<3> > bs(3);
        for(int i=0; i<3; ++i){
            for(int j=0; j<n[i]; ++j)
                bs[i][j] = true;
        }

        int a = 0;
        int b = 0;
        for(int i=0; i<3; ++i){
            if(bs[i][0] && bs[i][1] && bs[i][2])
                ++ a;
            if(bs[0][i] && bs[1][i] && bs[2][i])
                ++ b;
        }
        ret += max(a, b);

        cout << ret << endl;
    }
}