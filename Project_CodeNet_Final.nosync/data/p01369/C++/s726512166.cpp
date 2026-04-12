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
#define COUNT(i, n) for(int i = 1; i <= n; i ++)
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
const string L[2] = {"qwertasdfgzxcvb", "yuiophjklnm"};

int main(void){
    int res, cur;
    for(string s; cin >> s, s != "#"; cout << res << endl){
        res = 0;
        rep(i, s.size()){
            if(!i) cur = !!~L[0].find(s.at(i));
            if(~L[cur].find(s.at(i))) cur = !cur, res++;
        }
    }
 
    return 0;
}