#include <iostream>
//#include <set>
//#include <map>
//#include <iomanip>
#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
//#include <math.h>
#include <vector>
//#include <string>
//#include <list>
//#include <deque>
//#include <unordered_map>
//typedef long long LL;
//typedef long double LD;
using namespace std;

//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main() {
    int a;
    int b;
    int c;
    int x;
    int y;
    vector<int> ans(3);

    cin >> a >> b >> c >> x >> y;
    ans[0] = a*x+b*y;
    if(x>y){
        ans[1] = c*2*y+(x-y)*a;
    }else{
        ans[1] = c*2*x+(y-x)*b;
    }
    if(x>y){
        ans[2] = c*2*x;
    }else{
        ans[2] = c*2*y;
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;

    return 0;
}