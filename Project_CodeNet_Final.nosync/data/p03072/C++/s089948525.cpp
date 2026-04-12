#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
 
using namespace std;

int main(){
    int N;
    cin >> N;

    int ma = 0;
    int sum = 0;

    for(int i = 0; i < N; i++){
        int h;
        cin >> h;

        if(ma <= h){
            sum++;
            ma = h;
        }
    }

    cout << sum << endl;

    return 0;
}