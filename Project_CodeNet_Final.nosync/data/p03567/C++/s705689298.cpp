#import <iostream>
#import <string>
using namespace std;

int main() {
    string s;
    string AC = "AC";
    cin >> s;

    if (s.find(AC) != string::npos) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
