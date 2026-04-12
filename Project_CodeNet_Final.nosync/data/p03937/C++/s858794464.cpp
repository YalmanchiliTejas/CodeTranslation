#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int h, w;
    cin >> h >> w;
    int cnt = 0;
    rep(i, h){
        rep(j, w){
            char a;
            cin >> a;
            if(a == '#') cnt++;
        }
    }
    if(cnt == (h + w - 1)) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}