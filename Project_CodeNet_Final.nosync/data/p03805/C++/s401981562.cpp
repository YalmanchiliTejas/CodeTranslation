#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);
 
#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

vector< vector<int> > a(9);
vector<bool> used(9, false);
int n;
int answer;

void dfs(int p) { 
    int ret = 0;
    bool flag = true;
    for(int i=1;i<=n;i++) {
        if(!used[i]) flag = false;
    }
    //if(flag) return 1;
    if(flag) answer++;
    for(int i=0;i<a[p].size();i++) {
        if(!used[a[p][i]]) {
            used[a[p][i]] = true;
            //ret += dfs(a[p][i]);
            dfs(a[p][i]);
            used[a[p][i]] = false;
        }
    }
    //return ret;
}
int main(){
    int m;
    answer = 0;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int ai, bi;
        cin >> ai >> bi;
        a[ai].push_back(bi);
        a[bi].push_back(ai);
    }
    int ans = 0;
    for(int i=1;i<=1;i++) {
        if(!a[i].empty()) {
            used[i] = true;
            //ans += dfs(i);
            dfs(i);
            for(int j=0;j<used.size();j++) used[j]=false;
        }
    }
    cout << answer<< endl;
}
