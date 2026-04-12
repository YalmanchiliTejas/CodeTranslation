#include <iostream>
#include <string>

using namespace std;

int main() {
    string data;
    getline(cin, data);
    if (data.find("A") != string::npos && data.find("B") != string::npos) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}