#include <iostream>
#include <string>
using namespace std;

int main() {
    int r, g, b;
    int x, rgb;
    string s;
    cin >> r >> g >> b;
    rgb = (r*10*10)+(g*10)+(b);
    x = rgb%4 == 0;
    if ( x ) s = "YES";
    else s = "NO";
    cout << s << endl;
}