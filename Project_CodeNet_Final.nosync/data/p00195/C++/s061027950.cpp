#include <iostream>
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
#include <functional>
#include <bitset>

using namespace std;


signed main(){
    
    while(1){
    vector<pair<int, char>> vp(5);
    vp[0].second = 'A';   
    vp[1].second = 'B';   
    vp[2].second = 'C';   
    vp[3].second = 'D';   
    vp[4].second = 'E';
    bool flag = true;
    for(int i = 0; i < 5; i++){
        int a, b; cin >> a >> b;
        if(a == 0 and b == 0){
            flag = false;
            break;
        }
        vp[i].first = a + b;
    }

    if(flag == false) break;

    sort(vp.rbegin(), vp.rend());
    cout << vp[0].second << " " << vp[0].first << endl;
    }
    return 0;
}


