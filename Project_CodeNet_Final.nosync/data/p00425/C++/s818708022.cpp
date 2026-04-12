#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#define MP(a, b) make_pair(a, b)
#define MMP(a, b, c) make_pair(make_pair(a, b), c)
#define MAX 1000000000
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define LL_MIN (LL)-9223372036854775807
#define LL_MAX (LL)9223372036854775807
#define PI 3.14159265359

int main(){
    ios::sync_with_stdio(false);

    START:

    int n;
    cin >> n;
    if(n == 0) return 0;
    int state[7] = {0,1,2,3,4,5,6};
    int ans = 1;
    for(int i=0; i<n; i++){
        string S;
        cin >> S;
        int tmp;
        map<string,int> l;
        l["North"] = 0;
        l["East"] = 1;
        l["West"] = 2;
        l["South"] = 3;
        l["Right"] = 4;
        l["Left"] = 5;
        switch(l[S]){
            case 0:
                tmp = state[1];
                state[1] = state[2];
                state[2] = state[6];
                state[6] = state[5];
                state[5] = tmp;
                break;
            case 1:
                tmp = state[1];
                state[1] = state[4];
                state[4] = state[6];
                state[6] = state[3];
                state[3] = tmp;
                break;
            case 2:
                tmp = state[1];
                state[1] = state[3];
                state[3] = state[6];
                state[6] = state[4];
                state[4] = tmp;
                break;
            case 3:
                tmp = state[1];
                state[1] = state[5];
                state[5] = state[6];
                state[6] = state[2];
                state[2] = tmp;
                break;
            case 4:
                tmp = state[2];
                state[2] = state[3];
                state[3] = state[5];
                state[5] = state[4];
                state[4] = tmp;
                break;
            case 5:
                tmp = state[2];
                state[2] = state[4];
                state[4] = state[5];
                state[5] = state[3];
                state[3] = tmp;
                break;
        }
        ans += state[1];
    }
    cout << ans << endl;

    goto START;

    return 0;
}
