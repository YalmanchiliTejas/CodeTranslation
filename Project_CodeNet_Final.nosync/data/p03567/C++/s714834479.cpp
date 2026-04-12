#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    string ac = "AC";
    cin >> S;
    if (S.find(ac) == string::npos)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}