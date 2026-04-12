#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <sstream>

#define rep(i, n) for(int i = 0; i < n; i ++)
#define ALL(T) T.begin(), T.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(void){
    for(int n, sum = 0, ma, mi; cin >> n, n; cout << sum / (n - 2) << endl, sum = 0){
        rep(i, n){
            int s; cin >> s;
            if(!i) mi = s;
            else if(i == 1) ma = max(mi, s), mi = min(mi, s); 
            else if(s < mi) sum += mi, mi = s;
            else if(s > ma) sum += ma, ma = s;
            else sum += s;
        }
    }

    return 0;
}