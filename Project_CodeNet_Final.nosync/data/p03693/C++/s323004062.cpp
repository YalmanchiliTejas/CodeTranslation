#include <iostream>
#include <sstream>
using namespace std;

int main(){

    string r, g, b;
    cin >> r >> g >> b;

    int num;
    string s = r + g + b;

    istringstream iss(s);
    iss >> num;

    cout << ((num % 4 == 0) ? "YES" : "NO") << endl;
    return 0;
}