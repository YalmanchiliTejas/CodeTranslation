#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int a , b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    vector<int> var;
    var.push_back(a * x + b * y);
    var.push_back(max(x ,y) * 2 * c);
    if (a >= 2 * c && x < y)
        var.push_back( 2 * x * c + (y - x) * b);
    if (b >= 2 * c && y < x)
        var.push_back( 2 * y * c + (x - y) * a);
    
    if ( x > y)
        var.push_back(2 * y * c + (x - y) * a);
    else
        var.push_back(2 * x * c + (y - x) * b);
    
    cout << *min_element(var.begin(), var.end()) << endl;
    
}
