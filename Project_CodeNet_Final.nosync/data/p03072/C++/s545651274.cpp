#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <list>
using namespace std;

int main(){

    int n; cin >> n;

    int h[n];
    for(int i=0; i<n; i++){
        cin >> h[i];
    }

    int cnt = 1;

    int hmax = h[0];

    for(int i=1; i<n; i++){
        if(hmax <= h[i]){
            cnt++;
            hmax = h[i];
        }
    }

    cout << cnt;

    return 0;
}