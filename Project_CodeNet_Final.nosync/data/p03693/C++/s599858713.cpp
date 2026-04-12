#include<iostream>
#include<string>
using namespace std;

int main() {
    string r, g, b;
    cin >> r >> g >> b;

    string ans = r + g + b;
    cout << ((stoi(ans) % 4 == 0) ? "YES" : "NO") << endl;
}
