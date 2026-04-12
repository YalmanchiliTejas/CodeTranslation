#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    string input;
    cin >> input;
    if (input == "AAA" || input == "BBB")
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    
    return 0;
}