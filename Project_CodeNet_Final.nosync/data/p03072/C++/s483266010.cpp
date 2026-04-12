#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

int main() {
   
    int n;
    cin >> n;
    ll ans = 0;
    ll maxh = 0;
    for (ll i=0;i<n;i++){
        int h;
        cin >> h;
        if(maxh <= h){
            ans++;
            maxh = h;
        }
    }
    cout << ans << endl;

}