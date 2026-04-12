#include <iostream>

using namespace std;

int main() {
    string line; cin >> line;

    char last = line[0];
    for(int i = 0; i < 3; ++i) {
        if(last != line[i]) {
            cout << "Yes" << endl;
            return 0;
        }
        last = line[i];
    }

    cout << "No" << endl;
}
