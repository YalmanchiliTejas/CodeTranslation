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

typedef long long ll;

using namespace std;

int m[100005];

int main(){
    int n;

    cin >> n;

    int cnt = 0;
    int now = 0;
    rep(i, n){
        int in;
        cin >> in;
        if(now <= in){
            cnt++;
            now = in;
        }
    }
    cout << cnt << endl;
}