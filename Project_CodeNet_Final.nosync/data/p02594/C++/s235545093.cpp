#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pcont(x) for(auto i: x){cout << i << " ";} cout << "\n";

int main(){
    IOS;
    int x;
     cin >> x;
    if(x >= 30)cout << "Yes\n";
    else cout << "No\n";
    return 0;
}