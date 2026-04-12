#include <iostream>
#include <string>
using namespace std;

int main(void) {

    string str;

    cin >> str;
    if (str.find("A") != std::string::npos && str.find("B") != std::string::npos ){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }

    return 0;
}
