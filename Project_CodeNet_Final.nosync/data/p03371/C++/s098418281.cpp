#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using namespace std;
using vi = vector<int64_t>;
using vvi = vector<vi>;

int main(int argc, const char * argv[]) {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    // buy a and b => buy ab;
    if(2*c-a-b >= 0){
        cout << a*x + b*y << endl;;
    }else{
        int64_t cprice = c*2*min(x,y);
        int64_t remain = max(x,y) - min(x,y);
        if((x>y?a:b)<=c*2){
            cout << cprice + remain * (x>y?a:b) << endl;
        }else{
            cout << cprice + remain * c*2 << endl;
        }
    }
}
