#include <iostream>
#include <math.h>

using namespace std;

int main() {
    string S;
    cin >> S;
    string out ="Yes";
    if(S == "AAA" || S == "BBB") out = "No";
    cout << out << endl;
}
