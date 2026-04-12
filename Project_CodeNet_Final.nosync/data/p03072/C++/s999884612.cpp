#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void){
    int n;

    cin >> n;
    int high[n];
    for(int i = 0; i < n; i++){
        cin >> high[i];
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < i; j++){
            if(high[i] < high[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            res++;
        }
    }
    cout << res << endl;

    return 0;
}