#include<bits/stdc++.h>
using namespace std;

int main(void){
    int x, y, z;
    cin >> x >> y >> z;

    int cnt = 1;
    x = x - y - 2 * z;

    while(x >= y + z){
        cnt++;
        x = x - y - z;
    }
    printf("%d",cnt);
    return 0;
}