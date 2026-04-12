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
const int INF = 1001001001001001LL;
const int MOD = 1000000007;

signed main(){
    
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;
    k--;
    for(int i = 0; i < n; i++){
        if(s[i] != s[k]) s[i] = '*';
    }
    cout << s << endl;
    return 0;
}

