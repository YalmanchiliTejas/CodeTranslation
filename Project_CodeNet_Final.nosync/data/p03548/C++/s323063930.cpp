#include <iostream> // {{{
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdio> // }}}

#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,s,n) for(int i=s; i<n; i++)

using namespace std;

int main() {
    int x,y,z;
    cin >> x >> y >> z;
    rep(i,1000000){
        if((i*(y+z)+z) > x) {
            cout << i-1 << endl;
            break;
        }
    }
    return 0;
}
