#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int main(void){
    int x,y;
    cin >> x >> y;
    int ans = x*800 - (x/15)*200;
    cout << ans << endl;
    return 0;
}