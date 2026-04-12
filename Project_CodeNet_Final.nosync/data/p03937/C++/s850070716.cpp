#include <iostream>
using namespace std;

int main(){
    int h, w, count = 0;
    cin >> h >> w;
    char c;
    while(cin >> c) count += c == '#';
    cout << (count == h + w - 1 ? "Possible" : "Impossible") << endl;
}