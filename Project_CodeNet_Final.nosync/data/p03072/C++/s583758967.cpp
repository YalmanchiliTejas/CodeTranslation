#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>

#define _GLIBCXX_DEBUG
using namespace std;
using vi = vector<int64_t>;
using vvi = vector<vi>;

int main(int argc, const char * argv[]) {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t n;
    cin >> n;
    vi h(n);
    for(int i=0; i<n; i++){
        cin >> h.at(i);
    }
    int64_t res = 1, max = h.at(0);
    for(int i=1; i<n; i++){
        if(h.at(i) >= max){
            res++;
            max = h.at(i);
        }
    }
    cout << res << endl;
}
