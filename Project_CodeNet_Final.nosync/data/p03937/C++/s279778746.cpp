#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
#include<map>
#include<set>
#include <string>



using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)


map<string, int> mp;
#define ll long long

int main() {
    int h, w;
    cin >> h >> w;
    char cc;
    int c = 0;
    rep(i, h) {
        rep(j, w) {
            cin >>cc;
            if (cc == '#') {
                c++;
            }
        }
    }
    cout << (c == h + w - 1 ? "Possible" : "Impossible");
    return 0;
}