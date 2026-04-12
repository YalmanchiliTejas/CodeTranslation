
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
using namespace std;

void Main() {
    // input
    string S;
    cin >> S;


    // translate
    set<char> chars;
    for (auto c: S) {
        chars.insert(c);
    }


    // output
    if (chars.size() != 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
