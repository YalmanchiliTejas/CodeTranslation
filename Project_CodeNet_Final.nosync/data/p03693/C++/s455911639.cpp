#include <iostream>
#include <string>

using namespace std;

int main(){
    std::string r, g, b;
    cin >> r >> g >> b;
    std::string str = r + g + b;
    if(stoi(str) % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}