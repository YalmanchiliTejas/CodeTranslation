#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b;

    if ( (100*r + 10*g + b) % 4 == 0 ) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}