//  Copyright © 2017 Adán López Alatorre. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <stack>
#include <iomanip>
#include <climits>
#include <cmath>
#define fi first
#define se second
#define th second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef multiset<ll, greater<ll>>::iterator iit;
typedef pair<iit, iit> pvi;

const int maxN = 5e5 + 3, maxV = 1e5 + 5, LIM = 2e4;

int n, res[maxN];
ii arr[maxN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> arr[i].fi, arr[i].se = i;
    
    sort(arr, arr + n);
    
    for(int i = 0; i < (n >> 1); i++){
        res[arr[i].se] = arr[n >> 1].fi;
    }
    for(int i = (n >> 1); i < n; i++){
        res[arr[i].se] = arr[(n >> 1) - 1].fi;
    }
    for(int i = 0; i < n; i++) cout << res[i] << '\n';
    
}
