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

#define COUNT(i, n) for(int i = 1; i <= n; i ++)
#define rep(i, n) for(int i = 0; i < n; i ++)
#define ITER(c) __typeof((c).begin())
#define each(c, it) for(ITER(c) it =(c).begin(); it!=(c).end(); it++)
#define ALL(c) c.begin(), c.end()
#define mp make_pair
#define pb push_back
#define MEMSET(v, h) memset((v), h, sizeof(v))
 
using namespace std; 

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1 << 24;
const int N = 10000;

int main(void){
    vs t(N + 1);

    COUNT(i, N){
        stringstream ss;

        if(!(i % 5) || !(i % 3)){
            if(!(i % 3)) ss << "Fizz";
            if(!(i % 5)) ss << "Buzz";
        }
        else ss << i;

        t[i] = ss.str();
    }

    for(int m, n; cin >> m >> n, m; cout << endl){
        queue<int> rest;
        COUNT(i, m) rest.push(i);
        COUNT(i, n){
            int cur = rest.front(); rest.pop();
            string s; cin >> s;
            if(t[i] == s || rest.empty()) rest.push(cur);
        }

        vi res;
        while(!rest.empty()) res.pb(rest.front()), rest.pop();
        sort(ALL(res));
        rep(i, res.size()) cout << (i ? " ":"") << res[i];
    }
 
    return 0;
}