#include <iostream>
#include <string>
using namespace std;

int main(){
    string r, b, g;
    cin >> r >> g >> b;
    string rgb;
    rgb = r + g + b;
    int int_rgb;
    int_rgb = stoi(rgb);
    if (int_rgb % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}