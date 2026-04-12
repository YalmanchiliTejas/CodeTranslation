#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    while (true) {
        int sales[5][2];
        for (int i = 0; i < 5; i++) {
            cin >> sales[i][0] >> sales[i][1];
        }
        if (sales[0][0] == 0 && sales[0][1] == 0) {
            break;
        }
        int max[2] = {};
        for (int i = 0; i < 5; i++) {
            int s = sales[i][0] + sales[i][1];
            if (max[1] < s) {
                max[0] = i;
                max[1] = s;
            }
        }
        printf("%c %d\n", 'A' + max[0], max[1]);
    }
}