#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int h[n];
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    int res = 0;
    int max = 0;
    for(int i=0; i<n; i++){
        if(h[i] >= max){
            max = h[i];
            res ++;
        }
    }

    cout << res <<endl;

    return 0;
}