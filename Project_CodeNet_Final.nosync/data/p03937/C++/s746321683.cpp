#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;
typedef long long ll;

int main(){

    int h, w; cin >> h >> w;

    char a[h][w];

    int cnt = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a[i][j];
            if(a[i][j] == '#'){
                cnt++;
            }
        }
    }

    if(cnt == h + w - 1){
        cout << "Possible";
    }
    else{
        cout << "Impossible";
    }

    return 0;
}