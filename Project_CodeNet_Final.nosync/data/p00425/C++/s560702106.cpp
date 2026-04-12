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
    int N[] = {0,1,5,3};
    int E[] = {0,4,5,2};
    int W[] = {0,2,5,4};
    int S[] = {0,3,5,1};
    int R[] = {1,2,3,4};
    int L[] = {1,4,3,2};

    int* move[256];
    move['N'] = N;
    move['E'] = E;
    move['W'] = W;
    move['S'] = S;
    move['R'] = R;
    move['L'] = L;

    for(;;){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        int dice[] = {1,2,3,5,4,6};
        int ret = dice[0];
        for(int i=0; i<n; ++i){
            string s;
            cin >> s;
            char c = s[0];
            int tmp = dice[move[c][0]];
            for(int i=1; i<4; ++i)
                dice[move[c][i-1]] = dice[move[c][i]];
            dice[move[c][3]] = tmp;
            ret += dice[0];
        }

        cout << ret << endl;
    }
}