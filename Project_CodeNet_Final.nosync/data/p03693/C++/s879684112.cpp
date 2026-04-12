#include <iostream>
using namespace std;

int main(){
    int a, b, c, x;
    cin >> a >> b >> c;
    x = b * 10 + c;
    if((x % 4) == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}