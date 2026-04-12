#include <iostream>
using namespace std;
int main(void){
    string input;
    string r = "yuiophjklnm";
    while (cin >> input && input != "#") {
        int pre = 0, now = 0;
        int count = 0;
        int len = input.length();
        for (int i = 0; i < len; ++i) {
            char c = input[i];
            now = -1;
            for (int j = 0; j < 11; ++j) {
                if (c == r[j]) {
                    now = 1;
                    break;
                }
            }
            count += pre != 0 && pre != now;
            pre = now;
        }
        cout << count << endl;
    }
}