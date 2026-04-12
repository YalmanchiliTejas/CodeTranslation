#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    int cnt=0;
    for(int i=0;i<H*W;i++){
        char x;
        cin >> x;
        if(x == '#') cnt++;
    }
    if(cnt == H+W-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}