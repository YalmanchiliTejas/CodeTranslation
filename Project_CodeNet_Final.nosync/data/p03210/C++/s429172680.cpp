#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main(void){
    int x;
    cin >> x;
    
    if(x == 7 || x == 5 || x == 3){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}