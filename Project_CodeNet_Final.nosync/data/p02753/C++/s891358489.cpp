#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    string result = "No";
    if(S.find('A') != std::string::npos && S.find('B') != std::string::npos) {
        result = "Yes";
    }
    cout << result << endl;
    return 0;
}