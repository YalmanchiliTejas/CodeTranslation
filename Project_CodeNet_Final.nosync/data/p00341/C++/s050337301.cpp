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

signed main(){
    
    int a[1010] = {};
    for(int i = 0; i < 12; i++){
        int in; cin >> in;
        a[in]++;
    }

    int cnt = 0;
    for(int i = 0; i < 1000; i++){
        cnt += a[i] / 4;
    }

    if(cnt == 3) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}

