#include <iostream>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <cstring>

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))

#define INF (int)1e9+7

static const int dy[4] = {0,1,0,-1};
static const int dx[4] = {1,0,-1,0};

using namespace std;

typedef long long ll;

int main(){
    int a,b,c;
    int x,y;

    cin >> a >> b >> c >> x >> y;

    int p = max(x, y);

    ll plan[4];
    plan[0] = a*x + b*y;
    plan[1] = a*abs(x-y) + 2*c*y;
    plan[2] = b*abs(x-y) + 2*c*x;
    plan[3] = 2*c*p;
    
    ll mini = INF;
    rep(i, 4){
        mini = min(mini, plan[i]);
    }
    cout << mini << endl;
    return 0;
}