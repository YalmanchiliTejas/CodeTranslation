#include <iostream>
using namespace std;

int main(){
    int r,g,b;
    bool check;
    cin >> r >> g >> b;
    check = (r*100 + g * 10 + b) % 4 == 0;
    printf((check)?"YES":"NO");
}
