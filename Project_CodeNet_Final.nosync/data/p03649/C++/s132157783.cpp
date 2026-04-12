#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
int32_t main(){
    int n, ai;
    cin >> n;
    vector<int> v;
    for (int i=0; i < n; i++){
        cin >> ai;
        v.push_back(ai);
    }
    int ans = 0;
    while (true){
        int it = 0;
        vector<int> ops;
        for (int i=0; i < n; i++){
            int op = (v[i] - (n - 1)) / n;
            if ((v[i] - (n - 1)) % n != 0) op ++;
            if (v[i] <= n - 1) op = 0;
            ops.push_back(op);
            it += op;
        }
        ans += it;
        bool vv = true;
        for (int i=0; i < n; i++){
            v[i] -= n * ops[i];
            v[i] += (it - ops[i]);
            if (v[i] >= n) vv = false;
        }
        if (vv) break;
    }
    cout << ans << endl;
    return 0;
}
