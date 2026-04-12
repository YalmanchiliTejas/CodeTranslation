#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    string S;
    cin >> S;

    cout << (S.find('A') != string::npos && S.find('B') != string::npos ? "Yes" : "No") << endl;
}
