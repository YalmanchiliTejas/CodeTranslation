#include<iostream>
#include<string>
using namespace std;

int main() {
    int X;
    cin >> X;
    string can = "NO";
    if (X==3 || X==5 || X==7) can = "YES";
    cout << can << endl;
    return 0;
}