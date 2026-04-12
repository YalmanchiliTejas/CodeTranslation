#include <iostream>
#include <string>
using namespace std;

bool isLeft(char c) {
    string left = "qwertasdfgzxcvb";
    bool res = false;
    for (int i = 0; i < left.length(); ++i) {
        if (c == left[i]) {
            res = true;
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    string line;
    bool cur, prev;
    int cnt;
    while (cin >> line, line != "#") {
        cnt = 0;
        for (int i = 0; i < line.length(); ++i) {
            if (i == 0) {
                cur = isLeft(line[i]);
            } else {
                prev = cur;
                cur = isLeft(line[i]);
                if (prev != cur)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}