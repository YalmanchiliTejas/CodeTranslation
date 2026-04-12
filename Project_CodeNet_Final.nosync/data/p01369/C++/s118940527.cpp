#include <iostream>
#include <string>

using namespace std;

bool is_right(char c) {
    static char right[] = "yuiophjklnm";
    for (int i=0; right[i]; i++) {
        if (c == right[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    bool was_right;
    string input;
    while (true) {
        int count = 0;
        cin >> input;
        if (input == "#") {
            break;
        }
        for (int i=0; i<(int)input.length(); i++) {
            if (is_right(input[i])) {
                if (i>0 && !was_right) {
                    count++;
                }
                was_right = true;
            }
            else {
                if (i>0 && was_right) {
                    count++;
                }
                was_right = false;
            }
        }
        cout << count << endl;
    }
    return 0;
}