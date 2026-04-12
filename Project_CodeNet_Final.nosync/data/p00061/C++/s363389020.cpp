#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define rep(i, n) for(int i = 0; i < n; i ++)
#define ITER(c) __typeof((c).begin())
#define each(c, it) for(ITER(c) it =(c).begin(); it!=(c).end(); it++)
#define ALL(c) c.begin(), c.end()
#define mp make_pair
#define pb push_back
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define S first
#define T second

using namespace std; 

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1 << 24;
const int N = 101;

int main(void){
    vector<pii> in;
    char c;
    for(int t, s; cin >> t >> c >> s, t; in.pb(mp(s, t)));

    sort(ALL(in), greater<pii>());
    int cur = 0, pre = -1;
    vi res(N);
    each(in, it){
        if(it->S != pre) pre = it->S, cur ++;
        res[it->T] = cur;
    }

    for(int t; cin >> t; cout << res[t] << endl);
 
    return 0;
}